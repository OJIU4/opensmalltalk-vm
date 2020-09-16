/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2805 uuid: 48a26aae-6514-45a0-a30b-47c80fb69888
   from
	MD5Plugin CryptographyPlugins-ul.22 uuid: 1308f614-8494-46ef-bffd-21a70d1f8dee
 */
static char __buildInfo[] = "MD5Plugin CryptographyPlugins-ul.22 uuid: 1308f614-8494-46ef-bffd-21a70d1f8dee " __DATE__ ;



#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3
#define PrimErrBadNumArgs 5
#if !defined(VMBIGENDIAN) /* Allow this to be overridden on the compiler command line */
# define VMBIGENDIAN 0
#endif


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveDecodeState(void);
EXPORT(sqInt) primitiveInitializeState(void);
EXPORT(sqInt) primitivePluginAvailable(void);
EXPORT(sqInt) primitiveProcessBufferWithState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnBool)(sqInt boolean);
static sqInt (*methodReturnReceiver)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stSizeOf)(sqInt oop);
static sqInt (*stackObjectValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnBool(sqInt boolean);
extern sqInt methodReturnReceiver(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stSizeOf(sqInt oop);
extern sqInt stackObjectValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "MD5Plugin CryptographyPlugins-ul.22 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* MD5Plugin>>#primitiveDecodeState */
EXPORT(sqInt)
primitiveDecodeState(void)
{
    unsigned int *array;
    sqInt bytesOop;
    sqInt i;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	bytesOop = stackObjectValue(0);
	if (!((isBytes(bytesOop))
		 && ((stSizeOf(bytesOop)) == 16))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin decode:sizeInIntegers: */
	array = firstIndexableField(bytesOop);
	if (VMBIGENDIAN) {
		for (i = 0; i < 4; i += 1) {
			array[i] = (SQ_SWAP_4_BYTES((array[i])));
		}
	}
	methodReturnReceiver();
	return 0;
}

	/* MD5Plugin>>#primitiveInitializeState */
EXPORT(sqInt)
primitiveInitializeState(void)
{
    sqInt bytesOop;
    unsigned int *state;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	bytesOop = stackObjectValue(0);
	if (!((isBytes(bytesOop))
		 && ((stSizeOf(bytesOop)) == 16))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin md5InitializeState: */
	state = firstIndexableField(bytesOop);
	state[0] = 1732584193;
	state[1] = 4023233417U;
	state[2] = 2562383102U;
	state[3] = 271733878;
	methodReturnReceiver();
	return 0;
}

	/* MD5Plugin>>#primitivePluginAvailable */
EXPORT(sqInt)
primitivePluginAvailable(void)
{
	methodReturnBool(1);
	return 0;
}

	/* MD5Plugin>>#primitiveProcessBufferWithState */
EXPORT(sqInt)
primitiveProcessBufferWithState(void)
{
    unsigned int a;
    unsigned int b;
    unsigned int *buffer;
    sqInt bufferOop;
    unsigned int c;
    unsigned int d;
    sqInt i;
    unsigned int *state;
    sqInt stateOop;

	if (!((methodArgumentCount()) == 2)) {
		return primitiveFailFor(PrimErrBadNumArgs);
	}
	bufferOop = stackObjectValue(1);
	if (!((isBytes(bufferOop))
		 && ((stSizeOf(bufferOop)) == 64))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	stateOop = stackObjectValue(0);
	if (!((isBytes(stateOop))
		 && ((stSizeOf(stateOop)) == 16))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	/* begin md5ProcessBuffer:withState: */
	buffer = firstIndexableField(bufferOop);
	state = firstIndexableField(stateOop);
	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	/* begin decode:sizeInIntegers: */
	if (VMBIGENDIAN) {
		for (i = 0; i < 16; i += 1) {
			buffer[i] = (SQ_SWAP_4_BYTES((buffer[i])));
		}
	}
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[0])) + 3614090360U;
	a = ((((usqInt)(a) << 7)) | (((usqInt)(a)) >> (25))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[1])) + 3905402710U;
	d = ((((usqInt)(d) << 12)) | (((usqInt)(d)) >> (20))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[2])) + 606105819;
	c = ((((usqInt)(c) << 17)) | (((usqInt)(c)) >> (15))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[3])) + 3250441966U;
	b = ((((usqInt)(b) << 22)) | (((usqInt)(b)) >> (10))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[4])) + 4118548399U;
	a = ((((usqInt)(a) << 7)) | (((usqInt)(a)) >> (25))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[5])) + 1200080426;
	d = ((((usqInt)(d) << 12)) | (((usqInt)(d)) >> (20))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[6])) + 2821735955U;
	c = ((((usqInt)(c) << 17)) | (((usqInt)(c)) >> (15))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[7])) + 4249261313U;
	b = ((((usqInt)(b) << 22)) | (((usqInt)(b)) >> (10))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[8])) + 1770035416;
	a = ((((usqInt)(a) << 7)) | (((usqInt)(a)) >> (25))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[9])) + 2336552879U;
	d = ((((usqInt)(d) << 12)) | (((usqInt)(d)) >> (20))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[10])) + 4294925233U;
	c = ((((usqInt)(c) << 17)) | (((usqInt)(c)) >> (15))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[11])) + 2304563134U;
	b = ((((usqInt)(b) << 22)) | (((usqInt)(b)) >> (10))) + c;
	a += (((b & c) | (((unsigned int)~b) & d)) + (buffer[12])) + 1804603682;
	a = ((((usqInt)(a) << 7)) | (((usqInt)(a)) >> (25))) + b;
	d += (((a & b) | (((unsigned int)~a) & c)) + (buffer[13])) + 4254626195U;
	d = ((((usqInt)(d) << 12)) | (((usqInt)(d)) >> (20))) + a;
	c += (((d & a) | (((unsigned int)~d) & b)) + (buffer[14])) + 2792965006U;
	c = ((((usqInt)(c) << 17)) | (((usqInt)(c)) >> (15))) + d;
	b += (((c & d) | (((unsigned int)~c) & a)) + (buffer[15])) + 1236535329;
	b = ((((usqInt)(b) << 22)) | (((usqInt)(b)) >> (10))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[1])) + 4129170786U;
	a = ((((usqInt)(a) << 5)) | (((usqInt)(a)) >> (27))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[6])) + 3225465664U;
	d = ((((usqInt)(d) << 9)) | (((usqInt)(d)) >> (23))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[11])) + 643717713;
	c = ((((usqInt)(c) << 14)) | (((usqInt)(c)) >> (18))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[0])) + 3921069994U;
	b = ((((usqInt)(b) << 20)) | (((usqInt)(b)) >> (12))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[5])) + 3593408605U;
	a = ((((usqInt)(a) << 5)) | (((usqInt)(a)) >> (27))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[10])) + 38016083;
	d = ((((usqInt)(d) << 9)) | (((usqInt)(d)) >> (23))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[15])) + 3634488961U;
	c = ((((usqInt)(c) << 14)) | (((usqInt)(c)) >> (18))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[4])) + 3889429448U;
	b = ((((usqInt)(b) << 20)) | (((usqInt)(b)) >> (12))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[9])) + 568446438;
	a = ((((usqInt)(a) << 5)) | (((usqInt)(a)) >> (27))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[14])) + 3275163606U;
	d = ((((usqInt)(d) << 9)) | (((usqInt)(d)) >> (23))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[3])) + 4107603335U;
	c = ((((usqInt)(c) << 14)) | (((usqInt)(c)) >> (18))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[8])) + 1163531501;
	b = ((((usqInt)(b) << 20)) | (((usqInt)(b)) >> (12))) + c;
	a += (((b & d) | (c & ((unsigned int)~d))) + (buffer[13])) + 2850285829U;
	a = ((((usqInt)(a) << 5)) | (((usqInt)(a)) >> (27))) + b;
	d += (((a & c) | (b & ((unsigned int)~c))) + (buffer[2])) + 4243563512U;
	d = ((((usqInt)(d) << 9)) | (((usqInt)(d)) >> (23))) + a;
	c += (((d & b) | (a & ((unsigned int)~b))) + (buffer[7])) + 1735328473;
	c = ((((usqInt)(c) << 14)) | (((usqInt)(c)) >> (18))) + d;
	b += (((c & a) | (d & ((unsigned int)~a))) + (buffer[12])) + 2368359562U;
	b = ((((usqInt)(b) << 20)) | (((usqInt)(b)) >> (12))) + c;
	a += (((b ^ c) ^ d) + (buffer[5])) + 4294588738U;
	a = ((((usqInt)(a) << 4)) | (((usqInt)(a)) >> (28))) + b;
	d += (((a ^ b) ^ c) + (buffer[8])) + 2272392833U;
	d = ((((usqInt)(d) << 11)) | (((usqInt)(d)) >> (21))) + a;
	c += (((d ^ a) ^ b) + (buffer[11])) + 1839030562;
	c = ((((usqInt)(c) << 16)) | (((usqInt)(c)) >> (16))) + d;
	b += (((c ^ d) ^ a) + (buffer[14])) + 4259657740U;
	b = ((((usqInt)(b) << 23)) | (((usqInt)(b)) >> (9))) + c;
	a += (((b ^ c) ^ d) + (buffer[1])) + 2763975236U;
	a = ((((usqInt)(a) << 4)) | (((usqInt)(a)) >> (28))) + b;
	d += (((a ^ b) ^ c) + (buffer[4])) + 1272893353;
	d = ((((usqInt)(d) << 11)) | (((usqInt)(d)) >> (21))) + a;
	c += (((d ^ a) ^ b) + (buffer[7])) + 4139469664U;
	c = ((((usqInt)(c) << 16)) | (((usqInt)(c)) >> (16))) + d;
	b += (((c ^ d) ^ a) + (buffer[10])) + 3200236656U;
	b = ((((usqInt)(b) << 23)) | (((usqInt)(b)) >> (9))) + c;
	a += (((b ^ c) ^ d) + (buffer[13])) + 681279174;
	a = ((((usqInt)(a) << 4)) | (((usqInt)(a)) >> (28))) + b;
	d += (((a ^ b) ^ c) + (buffer[0])) + 3936430074U;
	d = ((((usqInt)(d) << 11)) | (((usqInt)(d)) >> (21))) + a;
	c += (((d ^ a) ^ b) + (buffer[3])) + 3572445317U;
	c = ((((usqInt)(c) << 16)) | (((usqInt)(c)) >> (16))) + d;
	b += (((c ^ d) ^ a) + (buffer[6])) + 76029189;
	b = ((((usqInt)(b) << 23)) | (((usqInt)(b)) >> (9))) + c;
	a += (((b ^ c) ^ d) + (buffer[9])) + 3654602809U;
	a = ((((usqInt)(a) << 4)) | (((usqInt)(a)) >> (28))) + b;
	d += (((a ^ b) ^ c) + (buffer[12])) + 3873151461U;
	d = ((((usqInt)(d) << 11)) | (((usqInt)(d)) >> (21))) + a;
	c += (((d ^ a) ^ b) + (buffer[15])) + 530742520;
	c = ((((usqInt)(c) << 16)) | (((usqInt)(c)) >> (16))) + d;
	b += (((c ^ d) ^ a) + (buffer[2])) + 3299628645U;
	b = ((((usqInt)(b) << 23)) | (((usqInt)(b)) >> (9))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[0])) + 4096336452U;
	a = ((((usqInt)(a) << 6)) | (((usqInt)(a)) >> (26))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[7])) + 1126891415;
	d = ((((usqInt)(d) << 10)) | (((usqInt)(d)) >> (22))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[14])) + 2878612391U;
	c = ((((usqInt)(c) << 15)) | (((usqInt)(c)) >> (17))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[5])) + 4237533241U;
	b = ((((usqInt)(b) << 21)) | (((usqInt)(b)) >> (11))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[12])) + 1700485571;
	a = ((((usqInt)(a) << 6)) | (((usqInt)(a)) >> (26))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[3])) + 2399980690U;
	d = ((((usqInt)(d) << 10)) | (((usqInt)(d)) >> (22))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[10])) + 4293915773U;
	c = ((((usqInt)(c) << 15)) | (((usqInt)(c)) >> (17))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[1])) + 2240044497U;
	b = ((((usqInt)(b) << 21)) | (((usqInt)(b)) >> (11))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[8])) + 1873313359;
	a = ((((usqInt)(a) << 6)) | (((usqInt)(a)) >> (26))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[15])) + 4264355552U;
	d = ((((usqInt)(d) << 10)) | (((usqInt)(d)) >> (22))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[6])) + 2734768916U;
	c = ((((usqInt)(c) << 15)) | (((usqInt)(c)) >> (17))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[13])) + 1309151649;
	b = ((((usqInt)(b) << 21)) | (((usqInt)(b)) >> (11))) + c;
	a += ((c ^ (b | ((unsigned int)~d))) + (buffer[4])) + 4149444226U;
	a = ((((usqInt)(a) << 6)) | (((usqInt)(a)) >> (26))) + b;
	d += ((b ^ (a | ((unsigned int)~c))) + (buffer[11])) + 3174756917U;
	d = ((((usqInt)(d) << 10)) | (((usqInt)(d)) >> (22))) + a;
	c += ((a ^ (d | ((unsigned int)~b))) + (buffer[2])) + 718787259;
	c = ((((usqInt)(c) << 15)) | (((usqInt)(c)) >> (17))) + d;
	b += ((d ^ (c | ((unsigned int)~a))) + (buffer[9])) + 3951481745U;
	b = ((((usqInt)(b) << 21)) | (((usqInt)(b)) >> (11))) + c;
	state[0] = ((state[0]) + a);
	state[1] = ((state[1]) + b);
	state[2] = ((state[2]) + c);
	state[3] = ((state[3]) + d);
	methodReturnReceiver();
	return 0;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnBool = interpreterProxy->methodReturnBool;
		methodReturnReceiver = interpreterProxy->methodReturnReceiver;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stSizeOf = interpreterProxy->stSizeOf;
		stackObjectValue = interpreterProxy->stackObjectValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "MD5Plugin";
void* MD5Plugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDecodeState\000\001", (void*)primitiveDecodeState},
	{(void*)_m, "primitiveInitializeState\000\001", (void*)primitiveInitializeState},
	{(void*)_m, "primitivePluginAvailable\000\377", (void*)primitivePluginAvailable},
	{(void*)_m, "primitiveProcessBufferWithState\000\001", (void*)primitiveProcessBufferWithState},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDecodeStateAccessorDepth = 1;
signed char primitiveInitializeStateAccessorDepth = 1;
signed char primitiveProcessBufferWithStateAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
