//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//

#ifndef OBJHEADER_COMMON_H_
#define OBJHEADER_COMMON_H_

// The GC is highly dependent on SIZE_OF_OBJHEADER being exactly the sizeof(ObjHeader)
// We define this macro so that the preprocessor can calculate padding structures.
// ClassAsValue: We use now 8 bytes for the object header by default
#define SIZEOF_OBJHEADER    8

// ClassAsVaue: Extra bits to handle identity allocated object on the stack
#define BIT_OBJHEADER_STACK_ALLOCATED   0x00000001
#define BIT_OBJHEADER_EMBED_ALLOCATED   0x00000002
#define BIT_OBJHEADER_EMBED_OFFSET_MASK 0xFFFFFFFC

#endif
