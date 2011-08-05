#ifndef _QEMU_ENCAP_
#define _QEMU_ENCAP_

#include "qemu_systemc.h"
#include "systemc_imports.h"

struct GDBState;

/*
 * Do not access cpu_{d,i}{cache,cache_data} directly; use the qi_* accessors
 * defined below.
 */
typedef struct 
{
    int                     id;
    int                     NOCPUs;
    unsigned long           (*cpu_dcache)[DCACHE_LINES];
    unsigned long           (*cpu_icache)[ICACHE_LINES];
    unsigned char           (*cpu_dcache_data)[DCACHE_LINES][DCACHE_LINE_BYTES];
    unsigned char           (*cpu_icache_data)[ICACHE_LINES][ICACHE_LINE_BYTES];
    void                    **irqs_systemc;

    void                    *first_cpu;
    void                    **envs;
    int                     io_mem_nb;
    void                    *io_mem_write;
    void                    *io_mem_read;
    void                    *io_mem_opaque;
    int                     io_mem_watch;
    void                    *ioport_opaque;
    void                    *ioport_read_table;
    void                    *ioport_write_table;
    void                    *l1_map;
    void                    **l1_phys_map;
    int                     nb_tbs;
    unsigned char           *phys_ram_dirty;
    int                     ram_size;
    void                    *tb_phys_hash;
    void                    *tbs;
    uint8_t                 code_gen_buffer[CODE_GEN_BUFFER_SIZE];
    uint8_t                 *code_gen_ptr;
    unsigned long           init_point_1;
    unsigned long           flush_head;

    struct GDBState         *gdb;

    struct systemc_import_t systemc;

    //log
    FILE                    *fim;
    FILE                    *fdm;
    unsigned long           log_cnt_instr;
    unsigned long           log_cnt_data;
} qemu_instance;

#define qi_dcache(qi)	((qi)->cpu_dcache)
#define qi_dcache_data(qi)	((qi)->cpu_dcache_data)
#define qi_icache(qi)	((qi)->cpu_icache)
#define qi_icache_data(qi)	((qi)->cpu_icache_data)

extern qemu_instance        *crt_qemu_instance;

#endif

