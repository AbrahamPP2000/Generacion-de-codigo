section .data
    a db 2     
    b db 1     
    c db 0     

section .text
global _start

print_result:
    mov ah, 0x09       
    mov edx, msg        
    int 0x21           
    
    mov dl, [c] 
    add dl, '0'        
    mov ah, 0x02        
    int 0x21           

    ret

_start:
    mov al, [a]  
    add al, [b]  

    mov [c], al 
    call print_result
    mov ah, 0x4C      
    int 0x21           

section .bss
    
