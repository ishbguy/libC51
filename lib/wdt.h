/* 
 * Name: wdt.h
 * Desc: Declararion functions of watch dog timer
 * Auth: ishbguy@hotmail.com
 * Date: 2016-07-14 20:34:12 
 *
 *   +-------------+--------+-------+-------+-------+--------+------+-------+------+
 *   | Name        |    7   |   6   |   5   |   4   |   3    |  2   |   1   |   0  |    
 *   +-------------+--------+-------+-------+-------+--------+------+-------+------+
 *   | WDT_CONTR   |    -   |   -   | EN_WDT|CLR_WDT|IDIL_WDT| PS2  |  PS1  |  PS0 |
 *   +-------------+--------+-------+-------+-------+--------+------+-------+------+
 *
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   | Mode  |  PS2  |  PS1 |  PS0 |Pre-Scale|    @20Mhz     |    @12Mhz    | @11.0592Mhz  |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   0   |   0   |   0  |   0  |    2    |    39.3ms     |    65.5ms    |   71.1ms     |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   1   |   0   |   0  |   1  |    4    |    78.6ms     |    131.0ms   |   142.2ms    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   2   |   0   |   1  |   0  |    8    |    157.3ms    |    262.1ms   |   284.4ms    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   3   |   0   |   1  |   1  |    16   |    314.6ms    |    524.2ms   |   568.8ms    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   4   |   1   |   0  |   0  |    32   |    619.1ms    |    1.0485s   |   1.1377s    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   5   |   1   |   0  |   1  |    64   |    1.25s      |    2.0971s   |   2.2755s    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   6   |   1   |   1  |   0  |   128   |    2.5s       |    4.1943s   |   4.5511s    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *   |   7   |   1   |   1  |   1  |   256   |    5s         |    8.3886s   |   9.1022s    |
 *   +-------+-------+------+------+---------+---------------+--------------+--------------+
 *                                                                                  
 */
#ifndef __WDT_H__
#define __WDT_H__

/* Register bit */
#define PS0                     (1 << 0)
#define PS1                     (1 << 1)
#define PS2                     (1 << 2)
#define IDIL_WDT                (1 << 3)
#define CLR_WDT                 (1 << 4)
#define EN_WDT                  (1 << 5)

/* WDT mode */
#define WdtMode0                (0 << 2 | 0 << 1 | 0 << 0)
#define WdtMode1                (0 << 2 | 0 << 1 | 1 << 0)
#define WdtMode2                (0 << 2 | 1 << 1 | 0 << 0)
#define WdtMode3                (0 << 2 | 1 << 1 | 1 << 0)
#define WdtMode4                (1 << 2 | 0 << 1 | 0 << 0)
#define WdtMode5                (1 << 2 | 0 << 1 | 1 << 0)
#define WdtMode6                (1 << 2 | 1 << 1 | 0 << 0)
#define WdtMode7                (1 << 2 | 1 << 1 | 1 << 0)

/* Macro functions */
#define WdtInit(mode)           do {    \
        WDT_CONTR |=  (mode | EN_WDT);  \
} while (0)

#define WdtFeed()               do {    \
        WDT_CONTR |= CLR_WDT;           \
} while (0)

#endif /* End of include guard: __WDT_H__ */
