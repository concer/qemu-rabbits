#ifndef _QEMU_SYSTEMC_H_
#define _QEMU_SYSTEMC_H_

#include <cfg.h>

#define CODE_GEN_BUFFER_SIZE     (8 * 1024 * 1024)

//#define COUNT_INSTR_FOR_STATISTICS

//#define LOG_INFO_FOR_DEBUG
//#define WRITE_PC_FOR_DEBUG

#define CYCLES_LATENCY_CACHE            2
#define CYCLES_LATENCY_CACHE_MISS       28
#define CYCLES_LATENCY_WRITE            1

#define NS_ICACHE_MISS                  92
#define NS_DCACHE_MISS                  92
#define NS_WRITE_ACCESS                 15

#define MEM_LIMIT           0x8000000

#define CACHE_BITS_TO_WORDS(bits)	(1 << ((bits) - 2))
#define CACHE_BITS_TO_BYTES(bits)	(1 <<  (bits))
#define CACHE_BITS_TO_MASK(bits)	(CACHE_BITS_TO_BYTES(bits) - 1)


#define DCACHE_LINES        256
#define DCACHE_LINE_BITS	5
#define DCACHE_LINE_WORDS	CACHE_BITS_TO_WORDS(DCACHE_LINE_BITS)
#define DCACHE_LINE_BYTES	CACHE_BITS_TO_BYTES(DCACHE_LINE_BITS)
#define DCACHE_LINE_MASK	CACHE_BITS_TO_MASK (DCACHE_LINE_BITS)

#define ICACHE_LINES        256
#define ICACHE_LINE_BITS	5
#define ICACHE_LINE_WORDS	CACHE_BITS_TO_WORDS(ICACHE_LINE_BITS)
#define ICACHE_LINE_BYTES	CACHE_BITS_TO_BYTES(ICACHE_LINE_BITS)
#define ICACHE_LINE_MASK	CACHE_BITS_TO_MASK (ICACHE_LINE_BITS)


#endif
