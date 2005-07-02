/*
 *  MIPS emulation memory micro-operations for qemu.
 * 
 *  Copyright (c) 2004-2005 Jocelyn Mayer
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* Standard loads and stores */
void glue(op_lb, MEMSUFFIX) (void)
{
    T0 = glue(ldsb, MEMSUFFIX)(T0);
    RETURN();
}

void glue(op_lbu, MEMSUFFIX) (void)
{
    T0 = glue(ldub, MEMSUFFIX)(T0);
    RETURN();
}

void glue(op_sb, MEMSUFFIX) (void)
{
    glue(stb, MEMSUFFIX)(T0, T1);
    RETURN();
}

void glue(op_lh, MEMSUFFIX) (void)
{
    T0 = glue(ldsw, MEMSUFFIX)(T0);
    RETURN();
}

void glue(op_lhu, MEMSUFFIX) (void)
{
    T0 = glue(lduw, MEMSUFFIX)(T0);
    RETURN();
}

void glue(op_sh, MEMSUFFIX) (void)
{
    glue(stw, MEMSUFFIX)(T0, T1);
    RETURN();
}

void glue(op_lw, MEMSUFFIX) (void)
{
    T0 = glue(ldl, MEMSUFFIX)(T0);
    RETURN();
}

void glue(op_sw, MEMSUFFIX) (void)
{
    glue(stl, MEMSUFFIX)(T0, T1);
    RETURN();
}

/* "half" load and stores */
void glue(op_lwl, MEMSUFFIX) (void)
{
    CALL_FROM_TB0(glue(do_lwl, MEMSUFFIX));
    RETURN();
}

void glue(op_lwr, MEMSUFFIX) (void)
{
    CALL_FROM_TB0(glue(do_lwr, MEMSUFFIX));
    RETURN();
}

void glue(op_swl, MEMSUFFIX) (void)
{
    CALL_FROM_TB0(glue(do_swl, MEMSUFFIX));
    RETURN();
}

void glue(op_swr, MEMSUFFIX) (void)
{
    CALL_FROM_TB0(glue(do_swr, MEMSUFFIX));
    RETURN();
}

void glue(op_ll, MEMSUFFIX) (void)
{
    T1 = T0;
    T0 = glue(ldl, MEMSUFFIX)(T0);
    env->CP0_LLAddr = T1;
    RETURN();
}

void glue(op_sc, MEMSUFFIX) (void)
{
    CALL_FROM_TB0(dump_sc);
    if (T0 == env->CP0_LLAddr) {
        glue(stl, MEMSUFFIX)(T0, T1);
        T0 = 1;
    } else {
        T0 = 0;
    }
    RETURN();
}