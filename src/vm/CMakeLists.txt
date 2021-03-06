set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Needed due to the cmunged files being in the binary folders, the set(CMAKE_INCLUDE_CURRENT_DIR ON) is not enough
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}) 

include_directories(${CLR_DIR}/src/gc)

if(CLR_CMAKE_PLATFORM_ARCH_AMD64)
    add_definitions(-D_TARGET_AMD64_=1)
    add_definitions(-DDBG_TARGET_64BIT=1)
    add_definitions(-DDBG_TARGET_AMD64=1)
    add_definitions(-DDBG_TARGET_WIN64=1)
elseif(CLR_CMAKE_PLATFORM_ARCH_I386)
    add_definitions(-D_TARGET_X86_=1)
    add_definitions(-DDBG_TARGET_32BIT=1)
    add_definitions(-DDBG_TARGET_X86=1)
    add_definitions(-DDBG_TARGET_WIN32=1)
elseif(CLR_CMAKE_PLATFORM_ARCH_ARM)
    add_definitions(-D_TARGET_ARM_=1)
    add_definitions(-DDBG_TARGET_32BIT=1)
    add_definitions(-DDBG_TARGET_ARM=1)
    add_definitions(-DDBG_TARGET_WIN32=1)
elseif(CLR_CMAKE_PLATFORM_ARCH_ARM64)
    add_definitions(-D_TARGET_ARM64_=1)
    add_definitions(-DDBG_TARGET_64BIT=1)
    add_definitions(-DDBG_TARGET_ARM64=1)
    add_definitions(-DDBG_TARGET_WIN64=1)
else()
    clr_unknown_arch()
endif()

include_directories(${ARCH_SOURCES_DIR})

add_definitions(-DFEATURE_LEAVE_RUNTIME_HOLDER=1)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

# Add the Merge flag here is needed
add_definitions(-DFEATURE_MERGE_JIT_AND_ENGINE)

if(CLR_CMAKE_PLATFORM_UNIX)
    add_compile_options(-fPIC)
endif(CLR_CMAKE_PLATFORM_UNIX)

set(VM_SOURCES_DAC_AND_WKS_COMMON
    appdomain.cpp
    array.cpp
    assembly.cpp
    baseassemblyspec.cpp
    binder.cpp
    ceeload.cpp
    certificatecache.cpp
    class.cpp
    classhash.cpp
    clsload.cpp
    codeman.cpp
    comdelegate.cpp
    contexts.cpp
    contractimpl.cpp
    coreassemblyspec.cpp
    corebindresult.cpp
    corhost.cpp
    crst.cpp
    debugdebugger.cpp
    debughelp.cpp
    debuginfostore.cpp
    decodemd.cpp
    dllimport.cpp
    domainfile.cpp
    dynamicmethod.cpp
    ecall.cpp
    eedbginterfaceimpl.cpp
    eehash.cpp
    eetwain.cpp
    encee.cpp
    excep.cpp
    exstate.cpp
    field.cpp
    formattype.cpp
    fptrstubs.cpp
    frames.cpp
    ../gc/gccommon.cpp
    gcdecode.cpp
    ../gc/gceesvr.cpp
    ../gc/gceewks.cpp
    ../gc/gcscan.cpp
    ../gc/gcsvr.cpp
    ../gc/gcwks.cpp
    genericdict.cpp
    generics.cpp
    ../gc/handletable.cpp
    ../gc/handletablecore.cpp
    ../gc/handletablescan.cpp
    hash.cpp
    hillclimbing.cpp
    ilstubcache.cpp
    ilstubresolver.cpp
    inlinetracking.cpp
    instmethhash.cpp
    jitinterface.cpp
    loaderallocator.cpp
    memberload.cpp
    method.cpp
    methodimpl.cpp
    methoditer.cpp
    methodtable.cpp
    object.cpp
    ../gc/objecthandle.cpp
    pefile.cpp
    peimage.cpp
    peimagelayout.cpp
    perfmap.cpp
    precode.cpp
    prestub.cpp
    readytoruninfo.cpp
    rejit.cpp
    securitydescriptor.cpp
    securitydescriptorassembly.cpp
    sigformat.cpp
    siginfo.cpp
    stackwalk.cpp
    stublink.cpp
    stubmgr.cpp
    syncblk.cpp
    threadpoolrequest.cpp
    threads.cpp
    threadstatics.cpp
    typectxt.cpp
    typedesc.cpp
    typehandle.cpp
    typehash.cpp
    typestring.cpp
    util.cpp
    vars.cpp
    virtualcallstub.cpp
    win32threadpool.cpp
    zapsig.cpp
)

set(VM_SOURCES_DAC
    ${VM_SOURCES_DAC_AND_WKS_COMMON}
    threaddebugblockinginfo.cpp
)

set(VM_SOURCES_WKS
    ${VM_SOURCES_DAC_AND_WKS_COMMON}
    appdomainhelper.cpp
    appdomainnative.cpp
    appdomainstack.cpp
    assemblyname.cpp
    assemblynative.cpp
    assemblysink.cpp
    assemblyspec.cpp
    cachelinealloc.cpp
    callhelpers.cpp
    ceemain.cpp
    clrex.cpp
    clrprivbinderutil.cpp
    clrvarargs.cpp
    comdatetime.cpp
    comdependenthandle.cpp
    comdynamic.cpp
    comisolatedstorage.cpp
    commemoryfailpoint.cpp
    commethodrental.cpp
    commodule.cpp
    compatibilityswitch.cpp
    comsynchronizable.cpp
    comthreadpool.cpp
    comutilnative.cpp
    comwaithandle.cpp
    constrainedexecutionregion.cpp
    coverage.cpp
    crossdomaincalls.cpp
    customattribute.cpp
    custommarshalerinfo.cpp
    dbggcinfodecoder.cpp
    dllimportcallback.cpp
    eeconfig.cpp
    eecontract.cpp
    eemessagebox.cpp
    eepolicy.cpp
    eetoprofinterfaceimpl.cpp
    eventstore.cpp
    exceptionhandling.cpp
    fcall.cpp
    fieldmarshaler.cpp
    finalizerthread.cpp
    frameworkexceptionloader.cpp
    gccover.cpp
    gcenv.cpp
    gchelpers.cpp
    gchost.cpp
    gcinfodecoder.cpp
    genmeth.cpp
    ../gc/handletablecache.cpp
    hostexecutioncontext.cpp
    hosting.cpp
    ibclogger.cpp
    ilmarshalers.cpp
    interopconverter.cpp
    interoputil.cpp
    interpreter.cpp
    invokeutil.cpp
    jithelpers.cpp
    listlock.cpp
    managedmdimport.cpp
    marshalnative.cpp
    marvin32.cpp
    mdaassistants.cpp
    message.cpp
    methodtablebuilder.cpp
    mlinfo.cpp
    mscorlib.cpp # <DisablePrecompiledHeaders>true</DisablePrecompiledHeaders>
    multicorejit.cpp # Condition="'$(FeatureMulticoreJIT)' == 'true'
    multicorejitplayer.cpp # Condition="'$(FeatureMulticoreJIT)' == 'true'
    nativeoverlapped.cpp
    objectlist.cpp
    olevariant.cpp
    pefingerprint.cpp
    pendingload.cpp
    perfdefaults.cpp
    profattach.cpp
    profattachclient.cpp
    profattachserver.cpp
    profdetach.cpp
    profilingenumerators.cpp
    profilinghelper.cpp
    proftoeeinterfaceimpl.cpp
    qcall.cpp
    reflectclasswriter.cpp
    reflectioninvocation.cpp
    runtimehandles.cpp
    rwlock.cpp
    safehandle.cpp
    security.cpp
    securityattributes.cpp
    securityconfig.cpp
    securitydeclarative.cpp
    securitydeclarativecache.cpp
    securitydescriptorappdomain.cpp
    securityhostprotection.cpp
    securitymeta.cpp
    securitypolicy.cpp
    securitytransparentassembly.cpp
    sha1.cpp
    simplerwlock.cpp
    sourceline.cpp
    spinlock.cpp
    stackingallocator.cpp
    stringliteralmap.cpp
    stubcache.cpp
    stubgen.cpp
    stubhelpers.cpp
    syncclean.cpp
    synch.cpp
    synchronizationcontextnative.cpp
    testhookmgr.cpp
    threaddebugblockinginfo.cpp
    threadsuspend.cpp
    typeequivalencehash.cpp
    typeparse.cpp
    verifier.cpp
    weakreferencenative.cpp
)

if(WIN32)

set(VM_SOURCES_DAC_AND_WKS_WIN32
    clrtocomcall.cpp
    comtoclrcall.cpp
    rcwwalker.cpp
    umthunkhash.cpp #" Condition="'$(FeatureMixedMode)' == 'true'
    winrttypenameconverter.cpp
)

list(APPEND VM_SOURCES_WKS 
    ${VM_SOURCES_DAC_AND_WKS_WIN32}
    # These should not be included for Linux
    appxutil.cpp
    assemblynativeresource.cpp
    classcompat.cpp
    classfactory.cpp
    clrprivbinderwinrt.cpp
    clrprivtypecachewinrt.cpp
    comcache.cpp
    comcallablewrapper.cpp
    comconnectionpoints.cpp
    cominterfacemarshaler.cpp
    commtmemberinfomap.cpp
    dispatchinfo.cpp
    dispparammarshaler.cpp
    dwreport.cpp
    eventreporter.cpp
    eventtrace.cpp
    extensibleclassfactory.cpp
    microsoft.comservices_i.c
    mngstdinterfaces.cpp
    notifyexternals.cpp
    olecontexthelpers.cpp
    profilermetadataemitvalidator.cpp
    rcwrefcache.cpp
    rtlfunctions.cpp
    runtimecallablewrapper.cpp
    securityprincipal.cpp
    stacksampler.cpp
    stdinterfaces.cpp
    stdinterfaces_wrapper.cpp
    winrthelpers.cpp    
)

list(APPEND VM_SOURCES_DAC 
    ${VM_SOURCES_DAC_AND_WKS_WIN32}
    # These should not be included for Linux
    clrprivbinderwinrt.cpp
    clrprivtypecachewinrt.cpp
)

if(CLR_CMAKE_PLATFORM_ARCH_AMD64)
    set(VM_SOURCES_WKS_ARCH_ASM
        ${ARCH_SOURCES_DIR}/AsmHelpers.asm
        ${ARCH_SOURCES_DIR}/CallDescrWorkerAMD64.asm
        ${ARCH_SOURCES_DIR}/ComCallPreStub.asm
        ${ARCH_SOURCES_DIR}/CrtHelpers.asm
        ${ARCH_SOURCES_DIR}/GenericComCallStubs.asm
        ${ARCH_SOURCES_DIR}/GenericComPlusCallStubs.asm
        ${ARCH_SOURCES_DIR}/getstate.asm
        ${ARCH_SOURCES_DIR}/InstantiatingStub.asm
        ${ARCH_SOURCES_DIR}/JitHelpers_Fast.asm
        ${ARCH_SOURCES_DIR}/JitHelpers_FastWriteBarriers.asm
        ${ARCH_SOURCES_DIR}/JitHelpers_InlineGetAppDomain.asm
        ${ARCH_SOURCES_DIR}/JitHelpers_InlineGetThread.asm
        ${ARCH_SOURCES_DIR}/JitHelpers_Slow.asm
        ${ARCH_SOURCES_DIR}/PInvokeStubs.asm
        ${ARCH_SOURCES_DIR}/RedirectedHandledJITCase.asm
        ${ARCH_SOURCES_DIR}/ThePreStubAMD64.asm
        ${ARCH_SOURCES_DIR}/ExternalMethodFixupThunk.asm
        ${ARCH_SOURCES_DIR}/TlsGetters.asm # Condition="'$(FeatureImplicitTls)' != 'true'
        ${ARCH_SOURCES_DIR}/UMThunkStub.asm
        ${ARCH_SOURCES_DIR}/VirtualCallStubAMD64.asm
    )
elseif(CLR_CMAKE_PLATFORM_ARCH_I386)
    set(VM_SOURCES_WKS_ARCH_ASM
        ${ARCH_SOURCES_DIR}/RedirectedHandledJITCase.asm
        ${ARCH_SOURCES_DIR}/asmhelpers.asm
        ${ARCH_SOURCES_DIR}/fptext.asm
        ${ARCH_SOURCES_DIR}/gmsasm.asm
        ${ARCH_SOURCES_DIR}/jithelp.asm
    )
endif()

else()

    if(CLR_CMAKE_PLATFORM_ARCH_AMD64)
        set(VM_SOURCES_WKS_ARCH_ASM
            ${ARCH_SOURCES_DIR}/calldescrworkeramd64.S
            ${ARCH_SOURCES_DIR}/crthelpers.S
            ${ARCH_SOURCES_DIR}/externalmethodfixupthunk.S
            ${ARCH_SOURCES_DIR}/getstate.S
            ${ARCH_SOURCES_DIR}/jithelpers_fast.S
            ${ARCH_SOURCES_DIR}/jithelpers_fastwritebarriers.S
            ${ARCH_SOURCES_DIR}/jithelpers_slow.S
            ${ARCH_SOURCES_DIR}/pinvokestubs.S
            ${ARCH_SOURCES_DIR}/theprestubamd64.S
            ${ARCH_SOURCES_DIR}/unixasmhelpers.S
            ${ARCH_SOURCES_DIR}/umthunkstub.S
            ${ARCH_SOURCES_DIR}/virtualcallstubamd64.S
        )
    elseif(CLR_CMAKE_PLATFORM_ARCH_ARM)
        set(VM_SOURCES_WKS_ARCH_ASM
            ${ARCH_SOURCES_DIR}/asmhelpers.S
            ${ARCH_SOURCES_DIR}/crthelpers.S
            ${ARCH_SOURCES_DIR}/ehhelpers.S
            ${ARCH_SOURCES_DIR}/memcpy.S
            ${ARCH_SOURCES_DIR}/patchedcode.S
        )
    elseif(CLR_CMAKE_PLATFORM_ARCH_ARM64)
        set(VM_SOURCES_WKS_ARCH_ASM
            ${ARCH_SOURCES_DIR}/asmhelpers.S
            ${ARCH_SOURCES_DIR}/calldescrworkerarm64.S
            ${ARCH_SOURCES_DIR}/crthelpers.S
            ${ARCH_SOURCES_DIR}/pinvokestubs.S
        )
    endif()
    
endif(WIN32)


if(CLR_CMAKE_PLATFORM_ARCH_AMD64)
    set(VM_SOURCES_DAC_AND_WKS_ARCH
        ${ARCH_SOURCES_DIR}/cgenamd64.cpp
        ${ARCH_SOURCES_DIR}/excepamd64.cpp
        ${ARCH_SOURCES_DIR}/gmsamd64.cpp
        ${ARCH_SOURCES_DIR}/stublinkeramd64.cpp
    )
    
    set(VM_SOURCES_WKS_ARCH
        ${ARCH_SOURCES_DIR}/jithelpersamd64.cpp
        ${ARCH_SOURCES_DIR}/jitinterfaceamd64.cpp
        ${ARCH_SOURCES_DIR}/profiler.cpp
        jitinterfacegen.cpp
    )
elseif(CLR_CMAKE_PLATFORM_ARCH_I386)
    set(VM_SOURCES_DAC_AND_WKS_ARCH
        exinfo.cpp
        ${ARCH_SOURCES_DIR}/cgenx86.cpp
        ${ARCH_SOURCES_DIR}/excepx86.cpp
        ${ARCH_SOURCES_DIR}/gmsx86.cpp
        ${ARCH_SOURCES_DIR}/stublinkerx86.cpp
    )
    
    set(VM_SOURCES_WKS_ARCH
        ${ARCH_SOURCES_DIR}/jithelp.asm
        ${ARCH_SOURCES_DIR}/jitinterfacex86.cpp
        ${ARCH_SOURCES_DIR}/profiler.cpp
    )
elseif(CLR_CMAKE_PLATFORM_ARCH_ARM)
    set(VM_SOURCES_DAC_AND_WKS_ARCH
        ${ARCH_SOURCES_DIR}/exceparm.cpp
        ${ARCH_SOURCES_DIR}/stubs.cpp
        ${ARCH_SOURCES_DIR}/armsinglestepper.cpp
    )
    
    set(VM_SOURCES_WKS_ARCH
        ${ARCH_SOURCES_DIR}/jithelpersarm.cpp
        ${ARCH_SOURCES_DIR}/profiler.cpp
    )
elseif(CLR_CMAKE_PLATFORM_ARCH_ARM64)
    set(VM_SOURCES_DAC_AND_WKS_ARCH
        ${ARCH_SOURCES_DIR}/cgenarm64.cpp
        ${ARCH_SOURCES_DIR}/stubs.cpp
    )
endif()

if(CLR_CMAKE_PLATFORM_UNIX)
    list(APPEND VM_SOURCES_WKS_ARCH
        ${ARCH_SOURCES_DIR}/unixstubs.cpp
    )
endif(CLR_CMAKE_PLATFORM_UNIX)

set(VM_SOURCES_DAC_ARCH
    gcinfodecoder.cpp
    dbggcinfodecoder.cpp
    exceptionhandling.cpp
)

list(APPEND VM_SOURCES_WKS 
    ${VM_SOURCES_WKS_ARCH}
    ${VM_SOURCES_DAC_AND_WKS_ARCH}
)

list(APPEND VM_SOURCES_DAC
    ${VM_SOURCES_DAC_ARCH}
    ${VM_SOURCES_DAC_AND_WKS_ARCH}
)

convert_to_absolute_path(VM_SOURCES_WKS ${VM_SOURCES_WKS})
convert_to_absolute_path(VM_SOURCES_WKS_ARCH_ASM ${VM_SOURCES_WKS_ARCH_ASM})
convert_to_absolute_path(VM_SOURCES_DAC ${VM_SOURCES_DAC})
    
add_subdirectory(dac)
add_subdirectory(wks)
