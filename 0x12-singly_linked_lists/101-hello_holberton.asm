section .data
    message db 'Hello, Holberton\n', 0
    format db '%s', 16, 0

section .text
    global main

    extern printf

main:
    push message
    push format
    call printf
    add rsp, 16
    mov eax, 0
    ret
