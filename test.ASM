.model small
.stack 100h
.data
    tbinput1 db 'nhap so thu nhat: $'
    tbinput2 db 'nhap so thu hai: $'
    tboutput1 db 'UCLN la: $'
    tboutput2 db 'BCNN la: $'
    input1 db 100,?,100 dup('$')
    input2 db 100,?,100 dup('$')
    endl db 13,10,'$'

    a db 0
    b db 0
    ucln db 0
    bcnn dw 0

.code

main proc

    mov ax, @data
    mov ds, ax

    mov ah, 09h
    lea dx, tbinput1
    int 21h

    mov ah, 0ah
    lea dx, input1
    int 21h

    lea si, input1 + 2

    call input
    mov a, al

    mov ah, 09h
    lea dx, endl
    int 21h

    mov ah, 09h
    lea dx, tbinput2
    int 21h

    mov ah, 0ah
    lea dx, input2
    int 21h

    lea si, input2 + 2

    call input
    mov b, al
    
    mov ah, 09h
    lea dx, endl
    int 21h

    mov bl, a
    mov dl, b

    call processucln
    
    mov ah, 02h
    mov dl, ucln
    add dl, '0'
    int 21h

    mov ah, 4ch
    int 21h


main endp

input proc
    mov ax,0
    mov bl,10
    mov dx,0    

    process:
        cmp [si], 13
        je endinput
        mul bl
        mov dl, [si]
        sub dl, '0'
        add ax, dx
        inc si
        jmp process

    endinput:
        ret
input endp

;description
processucln PROC
    mov dh,0
    for:
        mov bh, 0
        mov ax, bx
        mul dl
        cmp ax, 0
        je endUCLN
        cmp bl, dl
        jb below          ; bl < dl  
        jnb notbelow           ; bl >= dl
    
    below:
        mov ah, 0
        mov al, dl
        div bl
        mov dl, ah
        jmp for

    notbelow:
        mov ah, 0
        mov al, bl
        div dl
        mov bl, ah
        jmp for

    endUCLN:
        add bl, dl
        mov ucln, bl
        ret
processucln ENDP

;description
output PROC
    mov bl, 10
    mov dx, 0
    mov cx, 0
    processoutput:
        div bl
        mov dl, ah
        push dx
        cmp al, 0
        je print
        mov ah, 0
        jmp processoutput

    print:
        pop dx
        mov ah, 02h
        int 21h
        loop print

    ret
output ENDP

end main