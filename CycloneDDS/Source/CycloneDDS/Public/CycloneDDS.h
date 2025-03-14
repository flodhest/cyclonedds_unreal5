// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#ifndef DDSRT_STATIC_ASSERT_H
#define DDSRT_STATIC_ASSERT_H

#include <stdint.h> // Include standard integer types for _Generic

/* There are many tricks to use a constant expression to yield an
   illegal type or expression at compile time, such as zero-sized
   arrays and duplicate case or enum labels. So this is but one of the
   many tricks. */
#ifndef __MINGW32__
#define __MINGW32__ 0
#endif

#define DDSRT_STATIC_ASSERT2(line, pred)        \
  struct static_assert_##line {                 \
    char cond[(pred) ? 1 : -1];                 \
  }
#define DDSRT_STATIC_ASSERT1(line, pred)        \
  DDSRT_STATIC_ASSERT2 (line, pred)
#define DDSRT_STATIC_ASSERT(pred)               \
  DDSRT_STATIC_ASSERT1 (__LINE__, pred)

#ifndef _MSC_VER
#define DDSRT_STATIC_ASSERT_CODE(pred) do { switch(0) { case 0: case (pred): ; } } while (0)
#else
   /* Temporarily disabling warning C6326: Potential comparison of a
      constant with another constant. */
#define DDSRT_STATIC_ASSERT_CODE(pred) do {     \
    __pragma (warning (push))                   \
      __pragma (warning (disable : 6326))       \
      switch(0) { case 0: case (pred): ; }      \
    __pragma (warning (pop))                    \
  } while (0)
#endif

      // Define missing macros based on common build environments

      // Ensure DDSRT_WITH_FREERTOS, __GNUC__, __clang__ are defined
#ifndef DDSRT_WITH_FREERTOS
#define DDSRT_WITH_FREERTOS 0
#endif

#ifndef __GNUC__
#define __GNUC__ 0
#endif

#ifndef __clang__
#define __clang__ 0
#endif

#ifndef __GNUC_MINOR__
#define __GNUC_MINOR__ 0
#endif

#ifndef __GNUC_PATCHLEVEL__
#define __GNUC_PATCHLEVEL__ 0
#endif

#ifndef __clang_major__
#define __clang_major__ 0
#endif

#ifndef __clang_minor__
#define __clang_minor__ 0
#endif

#ifndef __clang_patchlevel__
#define __clang_patchlevel__ 0
#endif

// _Generic is C11, gcc and clang have supported it for a long time already
// and will happily do it also when compiling C99 code.  Microsoft did add
// it eventually, but only when compiling with /std:c11 according to the
// docs.
//
// Skipping the test for non-whitelisted cases means this should work on
// all Linux and macOS builds without breaking other platforms.  That is
// a reasonable compromise.
#if (__STDC__ == 1 && __STDC_VERSION__ >= 201112L) || \
    (__GNUC__*10000 + __GNUC_MINOR__*100 + __GNUC_PATCHLEVEL__) >= 40900 || \
    (__clang_major__*10000 + __clang_minor__*100 + __clang_patchlevel__) >= 30000
#define DDSRT_STATIC_ASSERT_IS_UNSIGNED(v_) \
  DDSRT_STATIC_ASSERT(_Generic(v_, \
    uint8_t: 1, uint16_t: 1, uint32_t: 1, uint64_t: 1, \
    default: 0))
#else
#define DDSRT_STATIC_ASSERT_IS_UNSIGNED(v_) DDSRT_STATIC_ASSERT(1)
#endif

#endif // DDSRT_STATIC_ASSERT_H

#include "CoreMinimal.h"
#include "Include/dds/dds.h"

class FCycloneDDSModule : public IModuleInterface
{
public:

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
};
