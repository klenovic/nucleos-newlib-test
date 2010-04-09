/*
 *  Copyright (C) 2009  Ladislav Klenovic <klenovic@nucleonsoft.com>
 *
 *  This file is part of Nucleos kernel.
 *
 *  Nucleos kernel is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 of the License.
 */
#include <nucleos/unistd.h>
#include <asm/syscall.h>
#include <errno.h>
#include <stdio.h>

int nosys(void)
{
	/* The message can't be on the stack, because the stack will vanish out
	 * from under us.  The send part of sendrec will succeed, but when
	 * a message is sent to restart the current process, who knows what will
	 * be in the place formerly occupied by the message?
	 */
	register unsigned int resultvar = 0;
	static int __msg[9];

	__msg[1] = 300;
	resultvar = (unsigned int)__msg;

	__asm__ __volatile__(ASM_SYSCALL_CALL_SYSTEM
		: "=a" (resultvar)
		: "0"(resultvar)
		: "memory", "cc"
	);

	if (__builtin_expect(INTERNAL_SYSCALL_ERROR_P(resultvar, ), 0)) {
		__set_errno (INTERNAL_SYSCALL_ERRNO (resultvar, ));
		return -1;
	}
	
	return resultvar;
}

int main(int argc, const char *argv[])
{
	int retval = nosys();

	printf("Return value:%d errno:%d\n", retval, errno);
}
