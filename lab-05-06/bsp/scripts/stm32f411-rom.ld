ENTRY(reset_handler)

MEMORY
{
    /* NAME(attr): ORIGIN = origin, LENGTH = len */
    FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    /*
    .secao :
    {
        *(.secao1)
    }>(vma) AT>(lma)
    VMA (Virtual Memory Address) & LMA (Load Memory Address)
    */
    
    /* Esta secao deve incluir a secao .text de todos arquivos objeto de entrada */
    .text :
    {
        /* combinar todas as secoes .isr_vectors de todos arquivos de entrada */
        /* combinar todas as secoes .text de todos arquivos de entrada */
        /* combinar todas as secoes .rodata de todos arquivos de entrada */
        KEEP(*(.isr_vectors)) /* MANTER SEM NENHUMA OTIMIZACAO */

        *(.text)
        . = ALIGN(4);

        *(.rodata)
        . = ALIGN(4);
      
        _etext = .;
        _la_data = _etext;

    }>FLASH /* vma == lma */


    /* Esta secao deve incluir a secao .data de todos arquivos objeto de entrada */
    .data :
    {
        _sdata = .;

        *(.data)
        . = ALIGN(4);

        _edata = .;

    }>SRAM AT> FLASH /* CARREGA NA FLASH, ao inicializar, COPIA PRA RAM */

    /* Esta secao deve incluir a secao .bss de todos arquivos objeto de entrada */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        . = ALIGN(4);

        _ebss = .;

    }>SRAM
}