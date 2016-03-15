warn: need id 20 but current id is 21
warn: need id 21 but current id is 20
warn: need id 35 but current id is 36
warn: need id 36 but current id is 35
warn: need id 43 but current id is 44
warn: need id 44 but current id is 43
warn: need id 47 but current id is 48
warn: need id 48 but current id is 47
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
    D3DKMDT_MFRC_UNINITIALIZED = 0,
    D3DKMDT_MFRC_ACTIVESIZE = 1,
    D3DKMDT_MFRC_MAXPIXELRATE = 2
} D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT;

typedef enum
{
    KeepObject = 1,
    DeallocateObject = 2,
    DeallocateObjectKeepRegisters = 3
} IO_ALLOCATION_ACTION;

typedef enum
{
    NotificationEvent = 0,
    SynchronizationEvent = 1
} EVENT_TYPE;

typedef enum
{
    DMM_MPA_UNINITIALIZED = 0,
    DMM_MPA_GDI = 1,
    DMM_MPA_VISTA = 2,
    DMM_MPA_GDI_VISTA_UNION = 3,
    DMM_MPA_MAXVALID = 3
} DMM_MODE_PRUNING_ALGORITHM;

typedef enum
{
    WheaErrTypeProcessor = 0,
    WheaErrTypeMemory = 1,
    WheaErrTypePCIExpress = 2,
    WheaErrTypeNMI = 3,
    WheaErrTypePCIXBus = 4,
    WheaErrTypePCIXDevice = 5,
    WheaErrTypeGeneric = 6
} WHEA_ERROR_TYPE;

typedef enum
{
    PMAP_COLORS = 0,
    PMAP_CURSORS = 1,
    PMAP_WINDOWSM = 2,
    PMAP_WINDOWSU = 3,
    PMAP_DESKTOP = 4,
    PMAP_ICONS = 5,
    PMAP_FONTS = 6,
    PMAP_TRUETYPE = 7,
    PMAP_KBDLAYOUT = 8,
    PMAP_INPUT = 9,
    PMAP_SUBSYSTEMS = 10,
    PMAP_BEEP = 11,
    PMAP_MOUSE = 12,
    PMAP_KEYBOARD = 13,
    PMAP_STICKYKEYS = 14,
    PMAP_KEYBOARDRESPONSE = 15,
    PMAP_MOUSEKEYS = 16,
    PMAP_TOGGLEKEYS = 17,
    PMAP_TIMEOUT = 18,
    PMAP_SOUNDSENTRY = 19,
    PMAP_SHOWSOUNDS = 20,
    PMAP_AEDEBUG = 21,
    PMAP_NETWORK = 22,
    PMAP_METRICS = 23,
    PMAP_UKBDLAYOUT = 24,
    PMAP_UKBDLAYOUTTOGGLE = 25,
    PMAP_WINLOGON = 26,
    PMAP_KEYBOARDPREF = 27,
    PMAP_SCREENREADER = 28,
    PMAP_HIGHCONTRAST = 29,
    PMAP_IMECOMPAT = 30,
    PMAP_IMM = 31,
    PMAP_POOLLIMITS = 32,
    PMAP_COMPAT32 = 33,
    PMAP_SETUPPROGRAMNAMES = 34,
    PMAP_INPUTMETHOD = 35,
    PMAP_MOUCLASS_PARAMS = 36,
    PMAP_KBDCLASS_PARAMS = 37,
    PMAP_COMPUTERNAME = 38,
    PMAP_TS = 39,
    PMAP_TABLETPC = 40,
    PMAP_MEDIACENTER = 41,
    PMAP_TS_EXCLUDE_DESKTOP_VERSION = 42,
    PMAP_WOW64_COMPAT32 = 43,
    PMAP_WOW64_IMECOMPAT = 44,
    PMAP_SERVERR2 = 45,
    PMAP_STARTER = 46,
    PMAP_ACCESS = 47,
    PMAP_AUDIODESCRIPTION = 48,
    PMAP_CONTROL = 49,
    PMAP_LAST = 49
} PROFILE_MAP;

typedef enum
{
    WheaDataFormatIPFSalRecord = 0,
    WheaDataFormatXPFMCA = 1,
    WheaDataFormatMemory = 2,
    WheaDataFormatPCIExpress = 3,
    WheaDataFormatNMIPort = 4,
    WheaDataFormatPCIXBus = 5,
    WheaDataFormatPCIXDevice = 6,
    WheaDataFormatGeneric = 7,
    WheaDataFormatMax = 8
} WHEA_ERROR_PACKET_DATA_FORMAT;

typedef enum
{
    D3DKMDT_MDT_UNINITIALIZED = 0,
    D3DKMDT_MDT_VESA_EDID_V1_BASEBLOCK = 1,
    D3DKMDT_MDT_VESA_EDID_V1_BLOCKMAP = 2,
    D3DKMDT_MDT_OTHER = 255
} D3DKMDT_MONITOR_DESCRIPTOR_TYPE;

typedef enum
{
    ThresholdMarginTop = 0,
    ThresholdMarginLeft = 1,
    ThresholdMarginRight = 2,
    ThresholdMarginBottom = 3,
    ThresholdMarginMax = 4
} eTHRESHOLD_MARGIN_DIRECTION;

typedef enum
{
    D3DKMDT_MCO_UNINITIALIZED = 0,
    D3DKMDT_MCO_DEFAULTMONITORPROFILE = 1,
    D3DKMDT_MCO_MONITORDESCRIPTOR = 2,
    D3DKMDT_MCO_MONITORDESCRIPTOR_REGISTRYOVERRIDE = 3,
    D3DKMDT_MCO_SPECIFICCAP_REGISTRYOVERRIDE = 4,
    D3DKMDT_MCO_DRIVER = 5,
    D3DKMDT_MCO_MAXVALID = 5
} D3DKMDT_MONITOR_CAPABILITIES_ORIGIN;

typedef enum
{
    D3DKMDT_MO_UNINITIALIZED = 0,
    D3DKMDT_MO_0DEG = 1,
    D3DKMDT_MO_90DEG = 2,
    D3DKMDT_MO_180DEG = 3,
    D3DKMDT_MO_270DEG = 4
} D3DKMDT_MONITOR_ORIENTATION;

typedef enum
{
    BusQueryDeviceID = 0,
    BusQueryHardwareIDs = 1,
    BusQueryCompatibleIDs = 2,
    BusQueryInstanceID = 3,
    BusQueryDeviceSerialNumber = 4,
    BusQueryContainerID = 5
} BUS_QUERY_ID_TYPE;

typedef enum
{
    PsReadIFEOAllValues = 0,
    PsSkipIFEODebugger = 1,
    PsSkipAllIFEO = 2,
    PsMaxIFEOKeyStates = 3
} PS_IFEO_KEY_STATE;

typedef enum
{
    D3DKMDT_VOT_UNINITIALIZED = 4294967294,
    D3DKMDT_VOT_OTHER = 4294967295,
    D3DKMDT_VOT_HD15 = 0,
    D3DKMDT_VOT_SVIDEO = 1,
    D3DKMDT_VOT_COMPOSITE_VIDEO = 2,
    D3DKMDT_VOT_COMPONENT_VIDEO = 3,
    D3DKMDT_VOT_DVI = 4,
    D3DKMDT_VOT_HDMI = 5,
    D3DKMDT_VOT_LVDS = 6,
    D3DKMDT_VOT_D_JPN = 8,
    D3DKMDT_VOT_SDI = 9,
    D3DKMDT_VOT_DISPLAYPORT_EXTERNAL = 10,
    D3DKMDT_VOT_DISPLAYPORT_EMBEDDED = 11,
    D3DKMDT_VOT_UDI_EXTERNAL = 12,
    D3DKMDT_VOT_UDI_EMBEDDED = 13,
    D3DKMDT_VOT_SDTVDONGLE = 14,
    D3DKMDT_VOT_INTERNAL = 2147483648,
    D3DKMDT_VOT_SVIDEO_4PIN = 1,
    D3DKMDT_VOT_SVIDEO_7PIN = 1,
    D3DKMDT_VOT_RF = 2,
    D3DKMDT_VOT_RCA_3COMPONENT = 3,
    D3DKMDT_VOT_BNC = 3
} D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY;

typedef enum
{
    D3DKMDT_VPPS_UNINITIALIZED = 0,
    D3DKMDT_VPPS_IDENTITY = 1,
    D3DKMDT_VPPS_CENTERED = 2,
    D3DKMDT_VPPS_STRETCHED = 3,
    D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX = 4,
    D3DKMDT_VPPS_CUSTOM = 5,
    D3DKMDT_VPPS_RESERVED1 = 253,
    D3DKMDT_VPPS_UNPINNED = 254,
    D3DKMDT_VPPS_NOTSPECIFIED = 255
} D3DKMDT_VIDPN_PRESENT_PATH_SCALING;

typedef enum
{
    SetSecurityDescriptor = 0,
    QuerySecurityDescriptor = 1,
    DeleteSecurityDescriptor = 2,
    AssignSecurityDescriptor = 3
} SECURITY_OPERATION_CODE;

typedef enum
{
    InterfaceTypeUndefined = 4294967295,
    Internal = 0,
    Isa = 1,
    Eisa = 2,
    MicroChannel = 3,
    TurboChannel = 4,
    PCIBus = 5,
    VMEBus = 6,
    NuBus = 7,
    PCMCIABus = 8,
    CBus = 9,
    MPIBus = 10,
    MPSABus = 11,
    ProcessorInternal = 12,
    InternalPowerBus = 13,
    PNPISABus = 14,
    PNPBus = 15,
    Vmcs = 16,
    MaximumInterfaceType = 17
} INTERFACE_TYPE;

typedef enum
{
    FileDirectoryInformation = 1,
    FileFullDirectoryInformation = 2,
    FileBothDirectoryInformation = 3,
    FileBasicInformation = 4,
    FileStandardInformation = 5,
    FileInternalInformation = 6,
    FileEaInformation = 7,
    FileAccessInformation = 8,
    FileNameInformation = 9,
    FileRenameInformation = 10,
    FileLinkInformation = 11,
    FileNamesInformation = 12,
    FileDispositionInformation = 13,
    FilePositionInformation = 14,
    FileFullEaInformation = 15,
    FileModeInformation = 16,
    FileAlignmentInformation = 17,
    FileAllInformation = 18,
    FileAllocationInformation = 19,
    FileEndOfFileInformation = 20,
    FileAlternateNameInformation = 21,
    FileStreamInformation = 22,
    FilePipeInformation = 23,
    FilePipeLocalInformation = 24,
    FilePipeRemoteInformation = 25,
    FileMailslotQueryInformation = 26,
    FileMailslotSetInformation = 27,
    FileCompressionInformation = 28,
    FileObjectIdInformation = 29,
    FileCompletionInformation = 30,
    FileMoveClusterInformation = 31,
    FileQuotaInformation = 32,
    FileReparsePointInformation = 33,
    FileNetworkOpenInformation = 34,
    FileAttributeTagInformation = 35,
    FileTrackingInformation = 36,
    FileIdBothDirectoryInformation = 37,
    FileIdFullDirectoryInformation = 38,
    FileValidDataLengthInformation = 39,
    FileShortNameInformation = 40,
    FileIoCompletionNotificationInformation = 41,
    FileIoStatusBlockRangeInformation = 42,
    FileIoPriorityHintInformation = 43,
    FileSfioReserveInformation = 44,
    FileSfioVolumeInformation = 45,
    FileHardLinkInformation = 46,
    FileProcessIdsUsingFileInformation = 47,
    FileNormalizedNameInformation = 48,
    FileNetworkPhysicalNameInformation = 49,
    FileIdGlobalTxDirectoryInformation = 50,
    FileIsRemoteDeviceInformation = 51,
    FileAttributeCacheInformation = 52,
    FileNumaNodeInformation = 53,
    FileStandardLinkInformation = 54,
    FileRemoteProtocolInformation = 55,
    FileMaximumInformation = 56
} FILE_INFORMATION_CLASS;

typedef enum
{
    NtProductWinNt = 1,
    NtProductLanManNt = 2,
    NtProductServer = 3
} NT_PRODUCT_TYPE;

typedef enum
{
    WheaErrSrcTypeMCE = 0,
    WheaErrSrcTypeCMC = 1,
    WheaErrSrcTypeCPE = 2,
    WheaErrSrcTypeNMI = 3,
    WheaErrSrcTypePCIe = 4,
    WheaErrSrcTypeGeneric = 5,
    WheaErrSrcTypeINIT = 6,
    WheaErrSrcTypeBOOT = 7,
    WheaErrSrcTypeSCIGeneric = 8,
    WheaErrSrcTypeIPFMCA = 9,
    WheaErrSrcTypeIPFCMC = 10,
    WheaErrSrcTypeIPFCPE = 11,
    WheaErrSrcTypeMax = 12
} WHEA_ERROR_SOURCE_TYPE;

typedef enum
{
    DMM_VMT_UNINITIALIZED = 0,
    DMM_VMT_PHYSICAL_MONITOR = 1,
    DMM_VMT_BOOT_PERSISTENT_MONITOR = 2,
    DMM_VMT_PERSISTENT_MONITOR = 3,
    DMM_VMT_TEMPORARY_MONITOR = 4,
    DMM_VMT_SIMULATED_MONITOR = 5
} DMM_VIDPN_MONITOR_TYPE;

typedef enum
{
    PsCreateInitialState = 0,
    PsCreateFailOnFileOpen = 1,
    PsCreateFailOnSectionCreate = 2,
    PsCreateFailExeFormat = 3,
    PsCreateFailMachineMismatch = 4,
    PsCreateFailExeName = 5,
    PsCreateSuccess = 6,
    PsCreateMaximumStates = 7
} PS_CREATE_STATE;

typedef enum
{
    D3DKMT_RenderCommandBuffer = 0,
    D3DKMT_DeferredCommandBuffer = 1,
    D3DKMT_SystemCommandBuffer = 2,
    D3DKMT_MmIoFlipCommandBuffer = 3,
    D3DKMT_WaitCommandBuffer = 4,
    D3DKMT_SignalCommandBuffer = 5,
    D3DKMT_DeviceCommandBuffer = 6,
    D3DKMT_SoftwareCommandBuffer = 7,
    D3DKMT_QueuePacketTypeMax = 8
} D3DKMT_QUERYSTATISTICS_QUEUE_PACKET_TYPE;

typedef enum
{
    SmStorageActual = 0,
    SmStorageNonActual = 1
} SM_STORAGE_MODIFIER;

typedef enum
{
    D3DKMDT_VPPR_UNINITIALIZED = 0,
    D3DKMDT_VPPR_IDENTITY = 1,
    D3DKMDT_VPPR_ROTATE90 = 2,
    D3DKMDT_VPPR_ROTATE180 = 3,
    D3DKMDT_VPPR_ROTATE270 = 4,
    D3DKMDT_VPPR_UNPINNED = 254,
    D3DKMDT_VPPR_NOTSPECIFIED = 255
} D3DKMDT_VIDPN_PRESENT_PATH_ROTATION;

typedef enum
{
    D3DKMT_ClientRenderBuffer = 0,
    D3DKMT_ClientPagingBuffer = 1,
    D3DKMT_SystemPagingBuffer = 2,
    D3DKMT_SystemPreemptionBuffer = 3,
    D3DKMT_DmaPacketTypeMax = 4
} D3DKMT_QUERYSTATISTICS_DMA_PACKET_TYPE;

typedef enum
{
    SystemPowerState = 0,
    DevicePowerState = 1
} POWER_STATE_TYPE;

typedef enum
{
    DMM_CT_UNINITIALIZED = 0,
    DMM_CT_CDD_NOPATHDATA = 1,
    DMM_CT_USERMODE = 2,
    DMM_CT_CDD_PATHDATA = 3,
    DMM_CT_DXGPORT = 4
} DMM_CLIENT_TYPE;

typedef enum
{
    D3DKMT_PreemptionAttempt = 0,
    D3DKMT_PreemptionAttemptSuccess = 1,
    D3DKMT_PreemptionAttemptMissNoCommand = 2,
    D3DKMT_PreemptionAttemptMissNotEnabled = 3,
    D3DKMT_PreemptionAttemptMissNextFence = 4,
    D3DKMT_PreemptionAttemptMissPagingCommand = 5,
    D3DKMT_PreemptionAttemptMissSplittedCommand = 6,
    D3DKMT_PreemptionAttemptMissFenceCommand = 7,
    D3DKMT_PreemptionAttemptMissRenderPendingFlip = 8,
    D3DKMT_PreemptionAttemptMissNotMakingProgress = 9,
    D3DKMT_PreemptionAttemptMissLessPriority = 10,
    D3DKMT_PreemptionAttemptMissRemainingQuantum = 11,
    D3DKMT_PreemptionAttemptMissRemainingPreemptionQuantum = 12,
    D3DKMT_PreemptionAttemptMissAlreadyPreempting = 13,
    D3DKMT_PreemptionAttemptMissGlobalBlock = 14,
    D3DKMT_PreemptionAttemptMissAlreadyRunning = 15,
    D3DKMT_PreemptionAttemptStatisticsMax = 16
} D3DKMT_QUERYRESULT_PREEMPTION_ATTEMPT_RESULT;

typedef enum
{
    PsNeverDuplicate = 0,
    PsRequestDuplicate = 1,
    PsAlwaysDuplicate = 2,
    PsMaxStdHandleStates = 3
} PS_STD_HANDLE_STATE;

typedef enum
{
    PsAttributeParentProcess = 0,
    PsAttributeDebugObject = 1,
    PsAttributeToken = 2,
    PsAttributeClientId = 3,
    PsAttributeTebAddress = 4,
    PsAttributeImageName = 5,
    PsAttributeImageInfo = 6,
    PsAttributeMemoryReserve = 7,
    PsAttributePriorityClass = 8,
    PsAttributeErrorMode = 9,
    PsAttributeStdHandleInfo = 10,
    PsAttributeHandleList = 11,
    PsAttributeGroupAffinity = 12,
    PsAttributePreferredNode = 13,
    PsAttributeIdealProcessor = 14,
    PsAttributeUmsThread = 15,
    PsAttributeExecuteOptions = 16,
    PsAttributeMax = 17
} PS_ATTRIBUTE_NUM;

typedef enum
{
    RegNtDeleteKey = 0,
    RegNtPreDeleteKey = 0,
    RegNtSetValueKey = 1,
    RegNtPreSetValueKey = 1,
    RegNtDeleteValueKey = 2,
    RegNtPreDeleteValueKey = 2,
    RegNtSetInformationKey = 3,
    RegNtPreSetInformationKey = 3,
    RegNtRenameKey = 4,
    RegNtPreRenameKey = 4,
    RegNtEnumerateKey = 5,
    RegNtPreEnumerateKey = 5,
    RegNtEnumerateValueKey = 6,
    RegNtPreEnumerateValueKey = 6,
    RegNtQueryKey = 7,
    RegNtPreQueryKey = 7,
    RegNtQueryValueKey = 8,
    RegNtPreQueryValueKey = 8,
    RegNtQueryMultipleValueKey = 9,
    RegNtPreQueryMultipleValueKey = 9,
    RegNtPreCreateKey = 10,
    RegNtPostCreateKey = 11,
    RegNtPreOpenKey = 12,
    RegNtPostOpenKey = 13,
    RegNtKeyHandleClose = 14,
    RegNtPreKeyHandleClose = 14,
    RegNtPostDeleteKey = 15,
    RegNtPostSetValueKey = 16,
    RegNtPostDeleteValueKey = 17,
    RegNtPostSetInformationKey = 18,
    RegNtPostRenameKey = 19,
    RegNtPostEnumerateKey = 20,
    RegNtPostEnumerateValueKey = 21,
    RegNtPostQueryKey = 22,
    RegNtPostQueryValueKey = 23,
    RegNtPostQueryMultipleValueKey = 24,
    RegNtPostKeyHandleClose = 25,
    RegNtPreCreateKeyEx = 26,
    RegNtPostCreateKeyEx = 27,
    RegNtPreOpenKeyEx = 28,
    RegNtPostOpenKeyEx = 29,
    RegNtPreFlushKey = 30,
    RegNtPostFlushKey = 31,
    RegNtPreLoadKey = 32,
    RegNtPostLoadKey = 33,
    RegNtPreUnLoadKey = 34,
    RegNtPostUnLoadKey = 35,
    RegNtPreQueryKeySecurity = 36,
    RegNtPostQueryKeySecurity = 37,
    RegNtPreSetKeySecurity = 38,
    RegNtPostSetKeySecurity = 39,
    RegNtCallbackObjectContextCleanup = 40,
    RegNtPreRestoreKey = 41,
    RegNtPostRestoreKey = 42,
    RegNtPreSaveKey = 43,
    RegNtPostSaveKey = 44,
    RegNtPreReplaceKey = 45,
    RegNtPostReplaceKey = 46,
    MaxRegNtNotifyClass = 47
} REG_NOTIFY_CLASS;

typedef enum
{
    D3DKMDT_VPPC_UNINITIALIZED = 0,
    D3DKMDT_VPPC_GRAPHICS = 1,
    D3DKMDT_VPPC_VIDEO = 2,
    D3DKMDT_VPPC_NOTSPECIFIED = 255
} D3DKMDT_VIDPN_PRESENT_PATH_CONTENT;

typedef enum
{
    D3DKMDT_RMT_UNINITIALIZED = 0,
    D3DKMDT_RMT_GRAPHICS = 1,
    D3DKMDT_RMT_TEXT = 2
} D3DKMDT_VIDPN_SOURCE_MODE_TYPE;

typedef enum
{
    ExceptionContinueExecution = 0,
    ExceptionContinueSearch = 1,
    ExceptionNestedException = 2,
    ExceptionCollidedUnwind = 3
} EXCEPTION_DISPOSITION;

typedef enum
{
    DMM_MPET_UNINITIALIZED = 0,
    DMM_MPET_ADDMONITOR = 1,
    DMM_MPET_REMOVEMONITOR = 2,
    DMM_MPET_DRIVERARRIVAL = 3,
    DMM_MPET_DRIVERQUERYREMOVE = 4,
    DMM_MPET_DRIVERREMOVECANCELLED = 5,
    DMM_MPET_DRIVERREMOVECOMPLETE = 6,
    DMM_MPET_DEVICENODEREADY = 7,
    DMM_MPET_EDIDCHANGE = 8,
    DMM_MPET_MONITORDISABLE = 9,
    DMM_MPET_MONITORENABLE = 10,
    DMM_MPET_ADAPTERADD = 11,
    DMM_MPET_ADAPTERREMOVAL = 12,
    DMM_MPET_INVALIDATION = 13,
    DMM_MPET_ADDSIMULATEDMONITOR = 1073741825,
    DMM_MPET_REMOVESIMULATEDMONITOR = 1073741826,
    DMM_MPET_MAXVALID = 1073741826
} DMM_MONITOR_PRESENCE_EVENT_TYPE;

typedef enum
{
    D3DKMDT_VPPI_UNINITIALIZED = 0,
    D3DKMDT_VPPI_PRIMARY = 1,
    D3DKMDT_VPPI_SECONDARY = 2,
    D3DKMDT_VPPI_TERTIARY = 3,
    D3DKMDT_VPPI_QUATERNARY = 4,
    D3DKMDT_VPPI_QUINARY = 5,
    D3DKMDT_VPPI_SENARY = 6,
    D3DKMDT_VPPI_SEPTENARY = 7,
    D3DKMDT_VPPI_OCTONARY = 8,
    D3DKMDT_VPPI_NONARY = 9,
    D3DKMDT_VPPI_DENARY = 10,
    D3DKMDT_VPPI_MAX = 32,
    D3DKMDT_VPPI_NOTSPECIFIED = 255
} D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE;

typedef enum
{
    COMIMAGE_FLAGS_ILONLY = 1,
    COMIMAGE_FLAGS_32BITREQUIRED = 2,
    COMIMAGE_FLAGS_IL_LIBRARY = 4,
    COMIMAGE_FLAGS_STRONGNAMESIGNED = 8,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT = 16,
    COMIMAGE_FLAGS_TRACKDEBUGDATA = 65536,
    COR_VERSION_MAJOR_V2 = 2,
    COR_VERSION_MAJOR = 2,
    COR_VERSION_MINOR = 0,
    COR_DELETED_NAME_LENGTH = 8,
    COR_VTABLEGAP_NAME_LENGTH = 8,
    NATIVE_TYPE_MAX_CB = 1,
    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE = 255,
    IMAGE_COR_MIH_METHODRVA = 1,
    IMAGE_COR_MIH_EHRVA = 2,
    IMAGE_COR_MIH_BASICBLOCK = 8,
    COR_VTABLE_32BIT = 1,
    COR_VTABLE_64BIT = 2,
    COR_VTABLE_FROM_UNMANAGED = 4,
    COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN = 8,
    COR_VTABLE_CALL_MOST_DERIVED = 16,
    IMAGE_COR_EATJ_THUNK_SIZE = 32,
    MAX_CLASS_NAME = 1024,
    MAX_PACKAGE_NAME = 1024
} ReplacesCorHdrNumericDefines;

typedef enum
{
    SmRangeSharedInfo = 0,
    SmRangeNonSharedInfo = 1,
    SmRangeBool = 2
} SM_RANGE_TYPES;

typedef enum
{
    GenericLessThan = 0,
    GenericGreaterThan = 1,
    GenericEqual = 2
} RTL_GENERIC_COMPARE_RESULTS;

typedef enum
{
    D3DKMDT_PVAM_UNINITIALIZED = 0,
    D3DKMDT_PVAM_DIRECT = 1,
    D3DKMDT_PVAM_PRESETPALETTE = 2,
    D3DKMDT_PVAM_SETTABLEPALETTE = 3,
    D3DKMDT_PVAM_MAXVALID = 3
} D3DKMDT_PIXEL_VALUE_ACCESS_MODE;

typedef enum
{
    D3DKMDT_TRF_UNINITIALIZED = 0
} D3DKMDT_TEXT_RENDERING_FORMAT;

typedef enum
{
    TP_CALLBACK_PRIORITY_HIGH = 0,
    TP_CALLBACK_PRIORITY_NORMAL = 1,
    TP_CALLBACK_PRIORITY_LOW = 2,
    TP_CALLBACK_PRIORITY_INVALID = 3
} TP_CALLBACK_PRIORITY;

typedef enum
{
    D3DKMDT_MTT_UNINITIALIZED = 0,
    D3DKMDT_MTT_ESTABLISHED = 1,
    D3DKMDT_MTT_STANDARD = 2,
    D3DKMDT_MTT_EXTRASTANDARD = 3,
    D3DKMDT_MTT_DETAILED = 4,
    D3DKMDT_MTT_DEFAULTMONITORPROFILE = 5,
    D3DKMDT_MTT_DRIVER = 6,
    D3DKMDT_MTT_MAXVALID = 6
} D3DKMDT_MONITOR_TIMING_TYPE;

typedef enum
{
    ResultNegative = 1,
    ResultZero = 0,
    ResultPositive = 2
} INTERLOCKED_RESULT;

typedef enum
{
    LowPoolPriority = 0,
    LowPoolPrioritySpecialPoolOverrun = 8,
    LowPoolPrioritySpecialPoolUnderrun = 9,
    NormalPoolPriority = 16,
    NormalPoolPrioritySpecialPoolOverrun = 24,
    NormalPoolPrioritySpecialPoolUnderrun = 25,
    HighPoolPriority = 32,
    HighPoolPrioritySpecialPoolOverrun = 40,
    HighPoolPrioritySpecialPoolUnderrun = 41
} EX_POOL_PRIORITY;

typedef enum
{
    DMM_CVR_UNINITIALIZED = 0,
    DMM_CVR_UPDATEMODALITY = 1,
    DMM_CVR_ADDPATH = 2,
    DMM_CVR_ADDPATHS = 3,
    DMM_CVR_REMOVEPATH = 4,
    DMM_CVR_REMOVEALLPATHS = 5
} DMM_VIDPNCHANGE_TYPE;

typedef enum
{
    DXGK_DIAG_CODE_POINT_TYPE_NONE = 0,
    DXGK_DIAG_CODE_POINT_TYPE_RECOMMEND_FUNC_VIDPN = 1,
    DXGK_DIAG_CODE_POINT_TYPE_OS_RECOMMENDED_VIDPN = 2,
    DXGK_DIAG_CODE_POINT_TYPE_SDC_LOG_FAILURE = 3,
    DXGK_DIAG_CODE_POINT_TYPE_SDC_INVALIDATE_ERROR = 4,
    DXGK_DIAG_CODE_POINT_TYPE_CDS_LOG_FAILURE = 5,
    DXGK_DIAG_CODE_POINT_TYPE_CDS_FAILURE_DB = 7,
    DXGK_DIAG_CODE_POINT_TYPE_RETRIEVE_BTL = 8,
    DXGK_DIAG_CODE_POINT_TYPE_RETRIEVE_DB = 9,
    DXGK_DIAG_CODE_POINT_TYPE_QDC_LOG_FAILURE = 10,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_ON_GDI = 11,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_OFF_GDI = 12,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_ON_MONITOR = 13,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_OFF_MONITOR = 14,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_DIM_MONITOR = 15,
    DXGK_DIAG_CODE_POINT_TYPE_POWER_UNDIM_MONITOR = 16,
    DXGK_DIAG_CODE_POINT_TYPE_BML_BACKTRACK = 17,
    DXGK_DIAG_CODE_POINT_TYPE_BML_CLOSEST_TARGET_MODE = 18,
    DXGK_DIAG_CODE_POINT_TYPE_BML_NO_EXACT_SOURCE_MODE = 19,
    DXGK_DIAG_CODE_POINT_TYPE_BML_NO_EXACT_TARGET_MODE = 20,
    DXGK_DIAG_CODE_POINT_TYPE_BML_SOURCE_MODE_NOT_PINNED = 21,
    DXGK_DIAG_CODE_POINT_TYPE_BML_TARGET_MODE_NOT_PINNED = 22,
    DXGK_DIAG_CODE_POINT_TYPE_BML_RESTARTED = 23,
    DXGK_DIAG_CODE_POINT_TYPE_TDR = 24,
    DXGK_DIAG_CODE_POINT_TYPE_ACPI_EVENT_NOTIFICATION = 25,
    DXGK_DIAG_CODE_POINT_TYPE_CREATEMDEV_USE_DEFAULT_MODE = 26,
    DXGK_DIAG_CODE_POINT_TYPE_CONNECTED_SET_LOG_FAILURE = 27,
    DXGK_DIAG_CODE_POINT_TYPE_INVALIDATE_DXGK_MODE_CACHE = 28,
    DXGK_DIAG_CODE_POINT_TYPE_REBUILD_DXGK_MODE_CACHE = 29,
    DXGK_DIAG_CODE_POINT_TYPE_CREATEFUNVIDPN_RELAX_REFRESH_MATCH = 30,
    DXGK_DIAG_CODE_POINT_TYPE_CREATEFUNVIDPN_CCDBML_FAIL_VISTABML_SUCCESSED = 31,
    DXGK_DIAG_CODE_POINT_TYPE_BML_BEST_SOURCE_MODE = 32,
    DXGK_DIAG_CODE_POINT_TYPE_BML_BEST_TARGET_MODE = 33,
    DXGK_DIAG_CODE_POINT_TYPE_ADD_DEVICE = 34,
    DXGK_DIAG_CODE_POINT_TYPE_START_ADAPTER = 35,
    DXGK_DIAG_CODE_POINT_TYPE_STOP_ADAPTER = 36,
    DXGK_DIAG_CODE_POINT_TYPE_CHILD_POLLING = 37,
    DXGK_DIAG_CODE_POINT_TYPE_CHILD_POLLING_TARGET = 38,
    DXGK_DIAG_CODE_POINT_TYPE_INDICATE_CHILD_STATUS = 39,
    DXGK_DIAG_CODE_POINT_TYPE_HANDLE_IRP = 40,
    DXGK_DIAG_CODE_POINT_TYPE_CHANGE_UNSUPPORTED_MONITOR_MODE_FLAG = 41,
    DXGK_DIAG_CODE_POINT_TYPE_ACPI_NOTIFY_CALLBACK = 42,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_EVICTALL_DISABLEGDI = 43,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_EVICTALL_ENABLEGDI = 44,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_MODESWITCH = 45,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_SYNC_MONITOR_EVENT = 46,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_PNP_NOTIFY_GDI = 47,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_PNP_ENABLE_VGA = 48,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_TDR_SWITCH_GDI = 49,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_CREATE_DEVICE_FAILED = 50,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_DEVICE_REMOVED = 51,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_DRVASSERTMODE_TRUE_FAILED = 52,
    DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_RECREATE_DEVICE_FAILED = 53,
    DXGK_DIAG_CODE_POINT_TYPE_CDD_MAPSHADOWBUFFER_FAILED = 54,
    DXGK_DIAG_CODE_POINT_TYPE_COMMIT_VIDPN_LOG_FAILURE = 55,
    DXGK_DIAG_CODE_POINT_TYPE_DRIVER_RECOMMEND_LOG_FAILURE = 56,
    DXGK_DIAG_CODE_POINT_TYPE_SDC_ENFORCED_CLONE_PATH_INVALID_SOURCE_IDX = 57,
    DXGK_DIAG_CODE_POINT_TYPE_DRVPROBEANDCAPTURE_FAILED = 58,
    DXGK_DIAG_CODE_POINT_TYPE_DXGKCDDENABLE_OPTIMIZED_MODE_CHANGE = 59,
    DXGK_DIAG_CODE_POINT_TYPE_DXGKSETDISPLAYMODE_OPTIMIZED_MODE_CHANGE = 60,
    DXGK_DIAG_CODE_POINT_TYPE_MON_DEPART_GETRECENTTOP_FAIL = 61,
    DXGK_DIAG_CODE_POINT_TYPE_MON_ARRIVE_INC_ADD_FAIL = 62,
    DXGK_DIAG_CODE_POINT_TYPE_CCD_DATABASE_PERSIST = 63,
    DXGK_DIAG_CODE_POINT_TYPE_CCD_DATABASE_PERSIST_NO_CONNECTIVITY_HASH = 64,
    DXGK_DIAG_CODE_POINT_TYPE_MAX = 64,
    DXGK_DIAG_CODE_POINT_TYPE_FORCE_UINT32 = 4294967295
} DXGK_DIAG_CODE_POINT_TYPE;

typedef enum
{
    D3DKMT_AllocationPriorityClassMinimum = 0,
    D3DKMT_AllocationPriorityClassLow = 1,
    D3DKMT_AllocationPriorityClassNormal = 2,
    D3DKMT_AllocationPriorityClassHigh = 3,
    D3DKMT_AllocationPriorityClassMaximum = 4,
    D3DKMT_MaxAllocationPriorityClass = 5
} D3DKMT_QUERYSTATISTICS_ALLOCATION_PRIORITY_CLASS;

typedef enum
{
    D3DDDIFMT_UNKNOWN = 0,
    D3DDDIFMT_R8G8B8 = 20,
    D3DDDIFMT_A8R8G8B8 = 21,
    D3DDDIFMT_X8R8G8B8 = 22,
    D3DDDIFMT_R5G6B5 = 23,
    D3DDDIFMT_X1R5G5B5 = 24,
    D3DDDIFMT_A1R5G5B5 = 25,
    D3DDDIFMT_A4R4G4B4 = 26,
    D3DDDIFMT_R3G3B2 = 27,
    D3DDDIFMT_A8 = 28,
    D3DDDIFMT_A8R3G3B2 = 29,
    D3DDDIFMT_X4R4G4B4 = 30,
    D3DDDIFMT_A2B10G10R10 = 31,
    D3DDDIFMT_A8B8G8R8 = 32,
    D3DDDIFMT_X8B8G8R8 = 33,
    D3DDDIFMT_G16R16 = 34,
    D3DDDIFMT_A2R10G10B10 = 35,
    D3DDDIFMT_A16B16G16R16 = 36,
    D3DDDIFMT_A8P8 = 40,
    D3DDDIFMT_P8 = 41,
    D3DDDIFMT_L8 = 50,
    D3DDDIFMT_A8L8 = 51,
    D3DDDIFMT_A4L4 = 52,
    D3DDDIFMT_V8U8 = 60,
    D3DDDIFMT_L6V5U5 = 61,
    D3DDDIFMT_X8L8V8U8 = 62,
    D3DDDIFMT_Q8W8V8U8 = 63,
    D3DDDIFMT_V16U16 = 64,
    D3DDDIFMT_W11V11U10 = 65,
    D3DDDIFMT_A2W10V10U10 = 67,
    D3DDDIFMT_UYVY = 1498831189,
    D3DDDIFMT_R8G8_B8G8 = 1195525970,
    D3DDDIFMT_YUY2 = 844715353,
    D3DDDIFMT_G8R8_G8B8 = 1111970375,
    D3DDDIFMT_DXT1 = 827611204,
    D3DDDIFMT_DXT2 = 844388420,
    D3DDDIFMT_DXT3 = 861165636,
    D3DDDIFMT_DXT4 = 877942852,
    D3DDDIFMT_DXT5 = 894720068,
    D3DDDIFMT_D16_LOCKABLE = 70,
    D3DDDIFMT_D32 = 71,
    D3DDDIFMT_D15S1 = 73,
    D3DDDIFMT_D24S8 = 75,
    D3DDDIFMT_D24X8 = 77,
    D3DDDIFMT_D24X4S4 = 79,
    D3DDDIFMT_D16 = 80,
    D3DDDIFMT_D32F_LOCKABLE = 82,
    D3DDDIFMT_D24FS8 = 83,
    D3DDDIFMT_D32_LOCKABLE = 84,
    D3DDDIFMT_S8_LOCKABLE = 85,
    D3DDDIFMT_S1D15 = 72,
    D3DDDIFMT_S8D24 = 74,
    D3DDDIFMT_X8D24 = 76,
    D3DDDIFMT_X4S4D24 = 78,
    D3DDDIFMT_L16 = 81,
    D3DDDIFMT_VERTEXDATA = 100,
    D3DDDIFMT_INDEX16 = 101,
    D3DDDIFMT_INDEX32 = 102,
    D3DDDIFMT_Q16W16V16U16 = 110,
    D3DDDIFMT_MULTI2_ARGB8 = 827606349,
    D3DDDIFMT_R16F = 111,
    D3DDDIFMT_G16R16F = 112,
    D3DDDIFMT_A16B16G16R16F = 113,
    D3DDDIFMT_R32F = 114,
    D3DDDIFMT_G32R32F = 115,
    D3DDDIFMT_A32B32G32R32F = 116,
    D3DDDIFMT_CxV8U8 = 117,
    D3DDDIFMT_A1 = 118,
    D3DDDIFMT_A2B10G10R10_XR_BIAS = 119,
    D3DDDIFMT_DXVACOMPBUFFER_BASE = 150,
    D3DDDIFMT_PICTUREPARAMSDATA = 150,
    D3DDDIFMT_MACROBLOCKDATA = 151,
    D3DDDIFMT_RESIDUALDIFFERENCEDATA = 152,
    D3DDDIFMT_DEBLOCKINGDATA = 153,
    D3DDDIFMT_INVERSEQUANTIZATIONDATA = 154,
    D3DDDIFMT_SLICECONTROLDATA = 155,
    D3DDDIFMT_BITSTREAMDATA = 156,
    D3DDDIFMT_MOTIONVECTORBUFFER = 157,
    D3DDDIFMT_FILMGRAINBUFFER = 158,
    D3DDDIFMT_DXVA_RESERVED9 = 159,
    D3DDDIFMT_DXVA_RESERVED10 = 160,
    D3DDDIFMT_DXVA_RESERVED11 = 161,
    D3DDDIFMT_DXVA_RESERVED12 = 162,
    D3DDDIFMT_DXVA_RESERVED13 = 163,
    D3DDDIFMT_DXVA_RESERVED14 = 164,
    D3DDDIFMT_DXVA_RESERVED15 = 165,
    D3DDDIFMT_DXVA_RESERVED16 = 166,
    D3DDDIFMT_DXVA_RESERVED17 = 167,
    D3DDDIFMT_DXVA_RESERVED18 = 168,
    D3DDDIFMT_DXVA_RESERVED19 = 169,
    D3DDDIFMT_DXVA_RESERVED20 = 170,
    D3DDDIFMT_DXVA_RESERVED21 = 171,
    D3DDDIFMT_DXVA_RESERVED22 = 172,
    D3DDDIFMT_DXVA_RESERVED23 = 173,
    D3DDDIFMT_DXVA_RESERVED24 = 174,
    D3DDDIFMT_DXVA_RESERVED25 = 175,
    D3DDDIFMT_DXVA_RESERVED26 = 176,
    D3DDDIFMT_DXVA_RESERVED27 = 177,
    D3DDDIFMT_DXVA_RESERVED28 = 178,
    D3DDDIFMT_DXVA_RESERVED29 = 179,
    D3DDDIFMT_DXVA_RESERVED30 = 180,
    D3DDDIFMT_DXVA_RESERVED31 = 181,
    D3DDDIFMT_DXVACOMPBUFFER_MAX = 181,
    D3DDDIFMT_BINARYBUFFER = 199,
    D3DDDIFMT_FORCE_UINT = 2147483647
} D3DDDIFORMAT;

typedef enum
{
    SecurityAnonymous = 0,
    SecurityIdentification = 1,
    SecurityImpersonation = 2,
    SecurityDelegation = 3
} SECURITY_IMPERSONATION_LEVEL;

typedef enum
{
    MoveRectKeepPositionAtCursor = 0,
    MoveRectMidTopAtCursor = 1,
    MoveRectKeepAspectRatioAtCursor = 2,
    MoveRectSidewiseKeepPositionAtCursor = 3
} MOVERECT_STYLE;

typedef enum
{
    StandardDesign = 0,
    NEC98x86 = 1,
    EndAlternatives = 2
} ALTERNATIVE_ARCHITECTURE_TYPE;

typedef enum
{
    PowerSystemUnspecified = 0,
    PowerSystemWorking = 1,
    PowerSystemSleeping1 = 2,
    PowerSystemSleeping2 = 3,
    PowerSystemSleeping3 = 4,
    PowerSystemHibernate = 5,
    PowerSystemShutdown = 6,
    PowerSystemMaximum = 7
} SYSTEM_POWER_STATE;

typedef enum
{
    TOUCHSTATE_INVALID = 4294967295,
    TOUCHSTATE_NONE = 0,
    TOUCHSTATE_DOWN = 1,
    TOUCHSTATE_MOVE = 2,
    TOUCHSTATE_UPOUTOFRANGE = 3,
    TOUCHSTATE_INAIR = 4,
    TOUCHSTATE_INAIRMOVE = 5,
    TOUCHSTATE_INAIROUTOFRANGE = 6,
    TOUCHSTATE_COUNT = 7
} TOUCHSTATE;

typedef enum
{
    D3DDDI_VSSLO_UNINITIALIZED = 0,
    D3DDDI_VSSLO_PROGRESSIVE = 1,
    D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST = 2,
    D3DDDI_VSSLO_INTERLACED_LOWERFIELDFIRST = 3,
    D3DDDI_VSSLO_OTHER = 255
} D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING;

typedef enum
{
    D3DKMDT_VSS_UNINITIALIZED = 0,
    D3DKMDT_VSS_VESA_DMT = 1,
    D3DKMDT_VSS_VESA_GTF = 2,
    D3DKMDT_VSS_VESA_CVT = 3,
    D3DKMDT_VSS_IBM = 4,
    D3DKMDT_VSS_APPLE = 5,
    D3DKMDT_VSS_NTSC_M = 6,
    D3DKMDT_VSS_NTSC_J = 7,
    D3DKMDT_VSS_NTSC_443 = 8,
    D3DKMDT_VSS_PAL_B = 9,
    D3DKMDT_VSS_PAL_B1 = 10,
    D3DKMDT_VSS_PAL_G = 11,
    D3DKMDT_VSS_PAL_H = 12,
    D3DKMDT_VSS_PAL_I = 13,
    D3DKMDT_VSS_PAL_D = 14,
    D3DKMDT_VSS_PAL_N = 15,
    D3DKMDT_VSS_PAL_NC = 16,
    D3DKMDT_VSS_SECAM_B = 17,
    D3DKMDT_VSS_SECAM_D = 18,
    D3DKMDT_VSS_SECAM_G = 19,
    D3DKMDT_VSS_SECAM_H = 20,
    D3DKMDT_VSS_SECAM_K = 21,
    D3DKMDT_VSS_SECAM_K1 = 22,
    D3DKMDT_VSS_SECAM_L = 23,
    D3DKMDT_VSS_SECAM_L1 = 24,
    D3DKMDT_VSS_EIA_861 = 25,
    D3DKMDT_VSS_EIA_861A = 26,
    D3DKMDT_VSS_EIA_861B = 27,
    D3DKMDT_VSS_PAL_K = 28,
    D3DKMDT_VSS_PAL_K1 = 29,
    D3DKMDT_VSS_PAL_L = 30,
    D3DKMDT_VSS_PAL_M = 31,
    D3DKMDT_VSS_OTHER = 255
} D3DKMDT_VIDEO_SIGNAL_STANDARD;

typedef enum
{
    DXGK_RFVR_UNINITIALIZED = 0,
    DXGK_RFVR_HOTKEY = 1,
    DXGK_RFVR_USERMODE = 2
} DXGK_RECOMMENDFUNCTIONALVIDPN_REASON;

typedef enum
{
    DXGK_DIAG_TYPE_NONE = 0,
    DXGK_DIAG_TYPE_SDC = 1,
    DXGK_DIAG_TYPE_HPD = 2,
    DXGK_DIAG_TYPE_DC_ORIGIN = 3,
    DXGK_DIAG_TYPE_USER_CDS = 4,
    DXGK_DIAG_TYPE_DRV_CDS = 5,
    DXGK_DIAG_TYPE_CODE_POINT = 6,
    DXGK_DIAG_TYPE_QDC = 7,
    DXGK_DIAG_TYPE_MONITOR_MGR = 8,
    DXGK_DIAG_TYPE_CONNECTEDSET_NOT_FOUND = 9,
    DXGK_DIAG_TYPE_DISPDIAG_COLLECTED = 10,
    DXGK_DIAG_TYPE_BML_PACKET = 11,
    DXGK_DIAG_TYPE_BML_PACKET_EX = 12,
    DXGK_DIAG_TYPE_COMMIT_VIDPN_FAILED = 13,
    DXGK_DIAG_TYPE_DRIVER_RECOMMEND_VIDPN = 14,
    DXGK_DIAG_TYPE_MAX = 14,
    DXGK_DIAG_TYPE_FORCE_UINT32 = 4294967295
} DXGK_DIAG_TYPE;

typedef enum
{
    ETW_THREAD_FLAG_HAD_INPUT = 0,
    ETW_THREAD_FLAG_HAD_VISIBLE_WINDOWS = 1,
    ETW_THREAD_FLAG_HAS_NEW_INPUT = 2,
    ETW_THREAD_FLAG_MAX = 3
} ETW_THREAD_FLAG;

typedef enum
{
    WheaErrSevRecoverable = 0,
    WheaErrSevFatal = 1,
    WheaErrSevCorrected = 2,
    WheaErrSevInformational = 3
} WHEA_ERROR_SEVERITY;

typedef enum
{
    KernelMode = 0,
    UserMode = 1,
    MaximumMode = 2
} MODE;

typedef enum
{
    IrqPriorityUndefined = 0,
    IrqPriorityLow = 1,
    IrqPriorityNormal = 2,
    IrqPriorityHigh = 3
} IRQ_PRIORITY;

typedef enum
{
    WARR_MOVE_FIRST = 10,
    WARR_RESTORE_UP = 10,
    WARR_RESTORE_DOWN = 11,
    WARR_VRESTORE_UP = 12,
    WARR_VRESTORE_DOWN = 13,
    WARR_VMAXIMIZE_RIGHT = 14,
    WARR_VMAXIMIZE_LEFT = 15,
    WARR_MOVE_NEXT_MONITOR_LEFT = 16,
    WARR_MOVE_NEXT_MONITOR_RIGHT = 17,
    WARR_MOVE_LAST = 18
} WINDOW_ARRANGEMENT_COMMAND;

typedef enum
{
    D3DDDI_GAMMARAMP_UNINITIALIZED = 0,
    D3DDDI_GAMMARAMP_DEFAULT = 1,
    D3DDDI_GAMMARAMP_RGB256x3x16 = 2,
    D3DDDI_GAMMARAMP_DXGI_1 = 3
} D3DDDI_GAMMARAMP_TYPE;

typedef enum
{
    MmFrameBufferCached = 2
} MEMORY_CACHING_TYPE_ORIG;

typedef enum
{
    D3DKMDT_VOT_DEPRECATED_UNINITIALIZED = 0,
    D3DKMDT_VOT_DEPRECATED_HD15 = 1,
    D3DKMDT_VOT_DEPRECATED_DVI = 2,
    D3DKMDT_VOT_DEPRECATED_HDMI = 3,
    D3DKMDT_VOT_DEPRECATED_HDMI2 = 4,
    D3DKMDT_VOT_DEPRECATED_SVIDEO_4PIN = 5,
    D3DKMDT_VOT_DEPRECATED_SVIDEO_7PIN = 6,
    D3DKMDT_VOT_DEPRECATED_RCA_COMPOSITE = 7,
    D3DKMDT_VOT_DEPRECATED_RCA_3COMPONENT = 8,
    D3DKMDT_VOT_DEPRECATED_BNC = 9,
    D3DKMDT_VOT_DEPRECATED_RF = 10,
    D3DKMDT_VOT_DEPRECATED_SDTVDONGLE = 11,
    D3DKMDT_VOT_DEPRECATED_INTERNAL = 12,
    D3DKMDT_VOT_DEPRECATED_OTHER = 255
} D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY_DEPRECATED;

typedef enum
{
    D3DKMDT_MP_UNINITIALIZED = 0,
    D3DKMDT_MP_PREFERRED = 1,
    D3DKMDT_MP_NOTPREFERRED = 2,
    D3DKMDT_MP_MAXVALID = 2
} D3DKMDT_MODE_PREFERENCE;

typedef enum
{
    ObCreateHandle = 0,
    ObOpenHandle = 1,
    ObDuplicateHandle = 2,
    ObInheritHandle = 3,
    ObMaxOpenReason = 4
} OB_OPEN_REASON;

typedef enum
{
    D3DKMDT_CB_UNINITIALIZED = 0,
    D3DKMDT_CB_INTENSITY = 1,
    D3DKMDT_CB_SRGB = 2,
    D3DKMDT_CB_SCRGB = 3,
    D3DKMDT_CB_YCBCR = 4,
    D3DKMDT_CB_YPBPR = 5,
    D3DKMDT_CB_MAXVALID = 5
} D3DKMDT_COLOR_BASIS;

typedef enum
{
    PowerActionNone = 0,
    PowerActionReserved = 1,
    PowerActionSleep = 2,
    PowerActionHibernate = 3,
    PowerActionShutdown = 4,
    PowerActionShutdownReset = 5,
    PowerActionShutdownOff = 6,
    PowerActionWarmEject = 7
} POWER_ACTION;

typedef enum
{
    ThresholdMouse = 0,
    ThresholdPen = 1,
    ThresholdMouseDragOut = 2,
    ThresholdPenDragOut = 3,
    ThresholdMouseSideMove = 4,
    ThresholdPenSideMove = 5,
    ThresholdAlways = 6,
    ThresholdLast = 7
} THRESHOLD_SELECTOR;

typedef enum
{
    DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED = 0,
    DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE = 1,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED = 2,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = 2,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST = 3,
    DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32 = 4294967295
} DISPLAYCONFIG_SCANLINE_ORDERING;

typedef enum
{
    DeviceUsageTypeUndefined = 0,
    DeviceUsageTypePaging = 1,
    DeviceUsageTypeHibernation = 2,
    DeviceUsageTypeDumpFile = 3
} DEVICE_USAGE_NOTIFICATION_TYPE;

typedef enum
{
    WCA_UNDEFINED = 0,
    WCA_NCRENDERING_ENABLED = 1,
    WCA_NCRENDERING_POLICY = 2,
    WCA_TRANSITIONS_FORCEDISABLED = 3,
    WCA_ALLOW_NCPAINT = 4,
    WCA_CAPTION_BUTTON_BOUNDS = 5,
    WCA_NONCLIENT_RTL_LAYOUT = 6,
    WCA_FORCE_ICONIC_REPRESENTATION = 7,
    WCA_FLIP3D_POLICY = 8,
    WCA_EXTENDED_FRAME_BOUNDS = 9,
    WCA_HAS_ICONIC_BITMAP = 10,
    WCA_THEME_ATTRIBUTES = 11,
    WCA_NCRENDERING_EXILED = 12,
    WCA_NCADORNMENTINFO = 13,
    WCA_EXCLUDED_FROM_LIVEPREVIEW = 14,
    WCA_VIDEO_OVERLAY_ACTIVE = 15,
    WCA_FORCE_ACTIVEWINDOW_APPEARANCE = 16,
    WCA_DISALLOW_PEEK = 17,
    WCA_LAST = 18
} WINDOWCOMPOSITIONATTRIB;

typedef enum
{
    SharedNtdll32LdrInitializeThunk = 0,
    SharedNtdll32KiUserExceptionDispatcher = 1,
    SharedNtdll32KiUserApcDispatcher = 2,
    SharedNtdll32KiUserCallbackDispatcher = 3,
    SharedNtdll32LdrHotPatchRoutine = 4,
    SharedNtdll32ExpInterlockedPopEntrySListFault = 5,
    SharedNtdll32ExpInterlockedPopEntrySListResume = 6,
    SharedNtdll32ExpInterlockedPopEntrySListEnd = 7,
    SharedNtdll32RtlUserThreadStart = 8,
    SharedNtdll32pQueryProcessDebugInformationRemote = 9,
    SharedNtdll32EtwpNotificationThread = 10,
    SharedNtdll32BaseAddress = 11,
    Wow64SharedPageEntriesCount = 12
} WOW64_SHARED_INFORMATION;

typedef enum
{
    BusRelations = 0,
    EjectionRelations = 1,
    PowerRelations = 2,
    RemovalRelations = 3,
    TargetDeviceRelation = 4,
    SingleBusRelations = 5,
    TransportRelations = 6
} DEVICE_RELATION_TYPE;

typedef enum
{
    D3DKMDT_VPPMT_UNINITIALIZED = 0,
    D3DKMDT_VPPMT_NOPROTECTION = 1,
    D3DKMDT_VPPMT_MACROVISION_APSTRIGGER = 2,
    D3DKMDT_VPPMT_MACROVISION_FULLSUPPORT = 3,
    D3DKMDT_VPPMT_NOTSPECIFIED = 255
} D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE;

typedef enum
{
    PowerDeviceUnspecified = 0,
    PowerDeviceD0 = 1,
    PowerDeviceD1 = 2,
    PowerDeviceD2 = 3,
    PowerDeviceD3 = 4,
    PowerDeviceMaximum = 5
} DEVICE_POWER_STATE;

typedef enum
{
    FileFsVolumeInformation = 1,
    FileFsLabelInformation = 2,
    FileFsSizeInformation = 3,
    FileFsDeviceInformation = 4,
    FileFsAttributeInformation = 5,
    FileFsControlInformation = 6,
    FileFsFullSizeInformation = 7,
    FileFsObjectIdInformation = 8,
    FileFsDriverPathInformation = 9,
    FileFsVolumeFlagsInformation = 10,
    FileFsMaximumInformation = 11
} FSINFOCLASS;

typedef enum
{
    NonPagedPool = 0,
    PagedPool = 1,
    NonPagedPoolMustSucceed = 2,
    DontUseThisType = 3,
    NonPagedPoolCacheAligned = 4,
    PagedPoolCacheAligned = 5,
    NonPagedPoolCacheAlignedMustS = 6,
    MaxPoolType = 7,
    NonPagedPoolSession = 32,
    PagedPoolSession = 33,
    NonPagedPoolMustSucceedSession = 34,
    DontUseThisTypeSession = 35,
    NonPagedPoolCacheAlignedSession = 36,
    PagedPoolCacheAlignedSession = 37,
    NonPagedPoolCacheAlignedMustSSession = 38
} POOL_TYPE;

typedef enum
{
    DeviceTextDescription = 0,
    DeviceTextLocationInformation = 1
} DEVICE_TEXT_TYPE;

///////////////////////////////////////////////////////////////////////////////
typedef struct _IMAGE_DOS_HEADER
{
    USHORT e_magic;
    USHORT e_cblp;
    USHORT e_cp;
    USHORT e_crlc;
    USHORT e_cparhdr;
    USHORT e_minalloc;
    USHORT e_maxalloc;
    USHORT e_ss;
    USHORT e_sp;
    USHORT e_csum;
    USHORT e_ip;
    USHORT e_cs;
    USHORT e_lfarlc;
    USHORT e_ovno;
    USHORT e_res[4];
    USHORT e_oemid;
    USHORT e_oeminfo;
    USHORT e_res2[10];
    LONG e_lfanew;
} IMAGE_DOS_HEADER;

typedef struct _LUID
{
    ULONG LowPart;
    LONG HighPart;
} LUID, *PLUID;

typedef struct _KDESCRIPTOR
{
    USHORT Pad[3];
    USHORT Limit;
    VOID *Base;
} KDESCRIPTOR, *PKDESCRIPTOR;

typedef struct _M128A
{
    ULONGLONG Low;
    LONGLONG High;
} M128A, *PM128A;

typedef union _WHEA_PERSISTENCE_INFO
{
    struct
    {
        ULONGLONG Signature : 16;
        ULONGLONG Length : 24;
        ULONGLONG Identifier : 16;
        ULONGLONG Attributes : 2;
        ULONGLONG DoNotLog : 1;
        ULONGLONG Reserved : 5;
    };
    ULONGLONG AsULONGLONG;
} WHEA_PERSISTENCE_INFO;

typedef union _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS
{
    struct
    {
        UCHAR FRUId : 1;
        UCHAR FRUText : 1;
        UCHAR Reserved : 6;
    };
    UCHAR AsUCHAR;
} WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS;

typedef struct _UNICODE_STRING
{
    USHORT Length;
    USHORT MaximumLength;
    USHORT *Buffer;
} UNICODE_STRING;

typedef struct _VK_FUNCTION_PARAM
{
    UCHAR NLSFEProcIndex;
    ULONG NLSFEProcParam;
} VK_FUNCTION_PARAM;

typedef struct _KLIST_ENTRY KLIST_ENTRY;

struct _KLIST_ENTRY
{
    KLIST_ENTRY *Flink;
    KLIST_ENTRY *Blink;
};

typedef struct _HRGN__
{
    INT unused;
} HRGN__;

typedef struct _HEAD
{
    VOID *h;
    ULONG cLockObj;
} HEAD, *PHEAD;

typedef struct _RECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT;

typedef struct _HDESK__
{
    INT unused;
} HDESK__;

typedef struct _RTL_BITMAP
{
    ULONG SizeOfBitMap;
    ULONG *Buffer;
} RTL_BITMAP;

typedef struct _HWINSTA__
{
    INT unused;
} HWINSTA__;

typedef struct _CLIP
{
    UINT fmt;
    VOID *hData;
    INT fGlobalHandle;
} CLIP, *PCLIP;

typedef struct _LARGE_UNICODE_STRING
{
    ULONG Length;
    ULONG MaximumLength : 31;
    ULONG bAnsi : 1;
    USHORT *Buffer;
} LARGE_UNICODE_STRING;

typedef struct _HIMC__
{
    INT unused;
} HIMC__;

typedef struct _UAHMENUPOPUPMETRICS
{
    INT rgcx[4];
    INT fUpdateMaxWidths : 1;
} UAHMENUPOPUPMETRICS, *PUAHMENUPOPUPMETRICS;

typedef struct _HBITMAP__
{
    INT unused;
} HBITMAP__;

typedef struct _SIZE
{
    LONG cx;
    LONG cy;
} SIZE, *PSIZE;

typedef struct _HBRUSH__
{
    INT unused;
} HBRUSH__;

typedef struct _D3DMATRIX
{
    FLOAT _11;
    FLOAT _12;
    FLOAT _13;
    FLOAT _14;
    FLOAT _21;
    FLOAT _22;
    FLOAT _23;
    FLOAT _24;
    FLOAT _31;
    FLOAT _32;
    FLOAT _33;
    FLOAT _34;
    FLOAT _41;
    FLOAT _42;
    FLOAT _43;
    FLOAT _44;
} D3DMATRIX, *PD3DMATRIX;

typedef struct _SBDATA
{
    INT posMin;
    INT posMax;
    INT page;
    INT pos;
} SBDATA, *PSBDATA;

typedef struct _PROP
{
    VOID *hData;
    USHORT atomKey;
    USHORT fs;
} PROP, *PPROP;

typedef struct _HWND__
{
    INT unused;
} HWND__;

typedef struct _MSGPPINFO
{
    ULONG dwIndexMsgPP;
} MSGPPINFO, *PMSGPPINFO;

typedef struct _TLSPRITESTATE
{
    UCHAR bInsideDriverCall;
    ULONG flOriginalSurfFlags;
    ULONG iOriginalType;
    ULONG flSpriteSurfFlags;
    ULONG iSpriteType;
    ULONG flags;
    ULONG iType;
    VOID *pState;
    VOID *pfnStrokeAndFillPath;
    VOID *pfnStrokePath;
    VOID *pfnFillPath;
    VOID *pfnPaint;
    VOID *pfnBitBlt;
    VOID *pfnCopyBits;
    VOID *pfnStretchBlt;
    VOID *pfnTextOut;
    VOID *pfnLineTo;
    VOID *pfnTransparentBlt;
    VOID *pfnAlphaBlend;
    VOID *pfnPlgBlt;
    VOID *pfnGradientFill;
    VOID *pfnSaveScreenBits;
    VOID *pfnStretchBltROP;
    VOID *pfnDrawStream;
} TLSPRITESTATE, *PTLSPRITESTATE;

typedef struct _POINT
{
    LONG x;
    LONG y;
} POINT, *PPOINT;

typedef struct _CLIENTTHREADINFO
{
    UINT CTIF_flags;
    USHORT fsChangeBits;
    USHORT fsWakeBits;
    USHORT fsWakeBitsJournal;
    USHORT fsWakeMask;
    ULONG tickLastMsgChecked;
} CLIENTTHREADINFO, *PCLIENTTHREADINFO;

typedef struct _HKL__
{
    INT unused;
} HKL__;

typedef struct _SBCALC
{
    INT posMin;
    INT posMax;
    INT page;
    INT pos;
    INT pxTop;
    INT pxBottom;
    INT pxLeft;
    INT pxRight;
    INT cpxThumb;
    INT pxUpArrow;
    INT pxDownArrow;
    INT pxStart;
    INT pxThumbBottom;
    INT pxThumbTop;
    INT cpx;
    INT pxMin;
} SBCALC, *PSBCALC;

typedef struct _HDC__
{
    INT unused;
} HDC__;

typedef struct _TL TL, *PTL;

struct _TL
{
    PTL next;
    VOID *pobj;
    VOID (*pfnFree)(VOID *);
};

typedef struct _LIST_ENTRY LIST_ENTRY;

struct _LIST_ENTRY
{
    LIST_ENTRY *Flink;
    LIST_ENTRY *Blink;
};

typedef struct _HTOUCHINPUT__
{
    INT unused;
} HTOUCHINPUT__;

typedef struct _IMEINFO
{
    ULONG dwPrivateDataSize;
    ULONG fdwProperty;
    ULONG fdwConversionCaps;
    ULONG fdwSentenceCaps;
    ULONG fdwUICaps;
    ULONG fdwSCSCaps;
    ULONG fdwSelectCaps;
} IMEINFO, *PIMEINFO;

typedef struct _VK_TO_BIT
{
    UCHAR Vk;
    UCHAR ModBits;
} VK_TO_BIT;

typedef struct _VSC_LPWSTR
{
    UCHAR vsc;
    USHORT *pwsz;
} VSC_LPWSTR;

typedef struct _VK_TO_WCHARS1
{
    UCHAR VirtualKey;
    UCHAR Attributes;
    WCHAR wch[1];
} VK_TO_WCHARS1;

typedef struct _DEADKEY
{
    ULONG dwBoth;
    WCHAR wchComposed;
    USHORT uFlags;
} DEADKEY, *PDEADKEY;

typedef struct _LIGATURE1
{
    UCHAR VirtualKey;
    USHORT ModificationNumber;
    WCHAR wch[1];
} LIGATURE1, *PLIGATURE1;

typedef struct _VSC_VK
{
    UCHAR Vsc;
    USHORT Vk;
} VSC_VK;

typedef struct _HGESTUREINFO__
{
    INT unused;
} HGESTUREINFO__;

typedef struct _RTL_BALANCED_LINKS RTL_BALANCED_LINKS;

struct _RTL_BALANCED_LINKS
{
    RTL_BALANCED_LINKS *Parent;
    RTL_BALANCED_LINKS *LeftChild;
    RTL_BALANCED_LINKS *RightChild;
    CHAR Balance;
    UCHAR Reserved[3];
};

typedef struct _EX_PUSH_LOCK
{
    union
    {
        struct
        {
            ULONGLONG Locked : 1;
            ULONGLONG Waiting : 1;
            ULONGLONG Waking : 1;
            ULONGLONG MultipleShared : 1;
            ULONGLONG Shared : 60;
        };
        ULONGLONG Value;
        VOID *Ptr;
    };
} EX_PUSH_LOCK;

typedef struct _HMONITOR__
{
    INT unused;
} HMONITOR__;

typedef struct _USERSTARTUPINFO
{
    ULONG cb;
    ULONG dwX;
    ULONG dwY;
    ULONG dwXSize;
    ULONG dwYSize;
    ULONG dwFlags;
    USHORT wShowWindow;
    USHORT cbReserved2;
} USERSTARTUPINFO, *PUSERSTARTUPINFO;

typedef union _LARGE_INTEGER
{
    struct
    {
        ULONG LowPart;
        LONG HighPart;
    };
    struct
    {
        ULONG LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

struct _EXCEPTION_RECORD
{
    LONG ExceptionCode;
    ULONG ExceptionFlags;
    EXCEPTION_RECORD *ExceptionRecord;
    VOID *ExceptionAddress;
    ULONG NumberParameters;
    ULONGLONG ExceptionInformation[15];
};

typedef struct _PROCESSOR_NUMBER
{
    USHORT Group;
    UCHAR Number;
    UCHAR Reserved;
} PROCESSOR_NUMBER;

typedef struct _KSPIN_LOCK_QUEUE KSPIN_LOCK_QUEUE;

struct _KSPIN_LOCK_QUEUE
{
    KSPIN_LOCK_QUEUE *Next;
    ULONGLONG *Lock;
};

typedef union _WHEA_ERROR_PACKET_FLAGS
{
    struct
    {
        ULONG PreviousError : 1;
        ULONG Reserved1 : 1;
        ULONG HypervisorError : 1;
        ULONG Simulated : 1;
        ULONG PlatformPfaControl : 1;
        ULONG PlatformDirectedOffline : 1;
        ULONG Reserved2 : 26;
    };
    ULONG AsULONG;
} WHEA_ERROR_PACKET_FLAGS;

typedef struct _GUID
{
    ULONG Data1;
    USHORT Data2;
    USHORT Data3;
    UCHAR Data4[8];
} GUID, *PGUID;

typedef struct _KTSS64
{
    ULONG Reserved0;
    ULONGLONG Rsp0;
    ULONGLONG Rsp1;
    ULONGLONG Rsp2;
    ULONGLONG Ist[8];
    ULONGLONG Reserved1;
    USHORT Reserved2;
    USHORT IoMapBase;
} KTSS64, *PKTSS64;

typedef union _KGDTENTRY64
{
    struct
    {
        USHORT LimitLow;
        USHORT BaseLow;
        union
        {
            struct
            {
                UCHAR BaseMiddle;
                UCHAR Flags1;
                UCHAR Flags2;
                UCHAR BaseHigh;
            } Bytes;
            struct
            {
                ULONG BaseMiddle : 8;
                ULONG Type : 5;
                ULONG Dpl : 2;
                ULONG Present : 1;
                ULONG LimitHigh : 4;
                ULONG System : 1;
                ULONG LongMode : 1;
                ULONG DefaultBig : 1;
                ULONG Granularity : 1;
                ULONG BaseHigh : 8;
            } Bits;
        };
        ULONG BaseUpper;
        ULONG MustBeZero;
    };
    ULONGLONG Alignment;
} KGDTENTRY64, *PKGDTENTRY64;

typedef union _KIDTENTRY64
{
    struct
    {
        USHORT OffsetLow;
        USHORT Selector;
        USHORT IstIndex : 3;
        USHORT Reserved0 : 5;
        USHORT Type : 5;
        USHORT Dpl : 2;
        USHORT Present : 1;
        USHORT OffsetMiddle;
        ULONG OffsetHigh;
        ULONG Reserved1;
    };
    ULONGLONG Alignment;
} KIDTENTRY64, *PKIDTENTRY64;

typedef struct _D3DKMDT_2DREGION
{
    UINT cx;
    UINT cy;
} D3DKMDT_2DREGION;

typedef struct _MDL MDL, *PMDL;

struct _MDL
{
    PMDL Next;
    SHORT Size;
    SHORT MdlFlags;
    EPROCESS *Process;
    VOID *MappedSystemVa;
    VOID *StartVa;
    ULONG ByteCount;
    ULONG ByteOffset;
};

typedef struct _SECTION_OBJECT_POINTERS
{
    VOID *DataSectionObject;
    VOID *SharedCacheMap;
    VOID *ImageSectionObject;
} SECTION_OBJECT_POINTERS;

typedef struct _IO_COMPLETION_CONTEXT
{
    VOID *Port;
    VOID *Key;
} IO_COMPLETION_CONTEXT;

typedef struct _OWNER_ENTRY
{
    ULONGLONG OwnerThread;
    union
    {
        struct
        {
            ULONG IoPriorityBoosted : 1;
            ULONG OwnerReferenced : 1;
            ULONG OwnerCount : 30;
        };
        ULONG TableSize;
    };
} OWNER_ENTRY;

typedef struct _COMPRESSED_DATA_INFO
{
    USHORT CompressionFormatAndEngine;
    UCHAR CompressionUnitShift;
    UCHAR ChunkShift;
    UCHAR ClusterShift;
    UCHAR Reserved;
    USHORT NumberOfChunks;
    ULONG CompressedChunkSizes[1];
} COMPRESSED_DATA_INFO;

typedef struct _IO_STATUS_BLOCK
{
    union
    {
        LONG Status;
        VOID *Pointer;
    };
    ULONGLONG Information;
} IO_STATUS_BLOCK;

typedef struct _SYSTEM_POWER_STATE_CONTEXT
{
    union
    {
        struct
        {
            ULONG Reserved1 : 8;
            ULONG TargetSystemState : 4;
            ULONG EffectiveSystemState : 4;
            ULONG CurrentSystemState : 4;
            ULONG IgnoreHibernationPath : 1;
            ULONG PseudoTransition : 1;
            ULONG Reserved2 : 10;
        };
        ULONG ContextAsUlong;
    };
} SYSTEM_POWER_STATE_CONTEXT;

typedef struct _INTERFACE
{
    USHORT Size;
    USHORT Version;
    VOID *Context;
    VOID (*InterfaceReference)(VOID *);
    VOID (*InterfaceDereference)(VOID *);
} INTERFACE, *PINTERFACE;

typedef struct _POWER_SEQUENCE
{
    ULONG SequenceD1;
    ULONG SequenceD2;
    ULONG SequenceD3;
} POWER_SEQUENCE;

typedef struct _SECURITY_SUBJECT_CONTEXT
{
    VOID *ClientToken;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    VOID *PrimaryToken;
    VOID *ProcessAuditId;
} SECURITY_SUBJECT_CONTEXT;

typedef struct _SECURITY_QUALITY_OF_SERVICE
{
    ULONG Length;
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
    UCHAR ContextTrackingMode;
    UCHAR EffectiveOnly;
} SECURITY_QUALITY_OF_SERVICE;

typedef struct _DEVICE_CAPABILITIES
{
    USHORT Size;
    USHORT Version;
    ULONG DeviceD1 : 1;
    ULONG DeviceD2 : 1;
    ULONG LockSupported : 1;
    ULONG EjectSupported : 1;
    ULONG Removable : 1;
    ULONG DockDevice : 1;
    ULONG UniqueID : 1;
    ULONG SilentInstall : 1;
    ULONG RawDeviceOK : 1;
    ULONG SurpriseRemovalOK : 1;
    ULONG WakeFromD0 : 1;
    ULONG WakeFromD1 : 1;
    ULONG WakeFromD2 : 1;
    ULONG WakeFromD3 : 1;
    ULONG HardwareDisabled : 1;
    ULONG NonDynamic : 1;
    ULONG WarmEjectSupported : 1;
    ULONG NoDisplayInUI : 1;
    ULONG Reserved1 : 1;
    ULONG Reserved : 13;
    ULONG Address;
    ULONG UINumber;
    DEVICE_POWER_STATE DeviceState[7];
    SYSTEM_POWER_STATE SystemWake;
    DEVICE_POWER_STATE DeviceWake;
    ULONG D1Latency;
    ULONG D2Latency;
    ULONG D3Latency;
} DEVICE_CAPABILITIES;

typedef union _POWER_STATE
{
    SYSTEM_POWER_STATE SystemState;
    DEVICE_POWER_STATE DeviceState;
} POWER_STATE;

typedef struct _D3DDDI_DXGI_RGB
{
    FLOAT Red;
    FLOAT Green;
    FLOAT Blue;
} D3DDDI_DXGI_RGB;

typedef struct _D3DDDI_GAMMA_RAMP_RGB256x3x16
{
    USHORT Red[256];
    USHORT Green[256];
    USHORT Blue[256];
} D3DDDI_GAMMA_RAMP_RGB256x3x16;

typedef struct _STRING
{
    USHORT Length;
    USHORT MaximumLength;
    CHAR *Buffer;
} STRING, *PSTRING;

typedef struct _IMAGE_FILE_HEADER
{
    USHORT Machine;
    USHORT NumberOfSections;
    ULONG TimeDateStamp;
    ULONG PointerToSymbolTable;
    ULONG NumberOfSymbols;
    USHORT SizeOfOptionalHeader;
    USHORT Characteristics;
} IMAGE_FILE_HEADER;

typedef struct _D3DDDI_RATIONAL
{
    UINT Numerator;
    UINT Denominator;
} D3DDDI_RATIONAL;

typedef union _WHEA_ERROR_RECORD_HEADER_VALIDBITS
{
    struct
    {
        ULONG PlatformId : 1;
        ULONG Timestamp : 1;
        ULONG PartitionId : 1;
        ULONG Reserved : 29;
    };
    ULONG AsULONG;
} WHEA_ERROR_RECORD_HEADER_VALIDBITS;

typedef union _WHEA_REVISION
{
    struct
    {
        UCHAR MinorRevision;
        UCHAR MajorRevision;
    };
    USHORT AsUSHORT;
} WHEA_REVISION;

typedef union _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS
{
    struct
    {
        ULONG Primary : 1;
        ULONG ContainmentWarning : 1;
        ULONG Reset : 1;
        ULONG ThresholdExceeded : 1;
        ULONG ResourceNotAvailable : 1;
        ULONG LatentError : 1;
        ULONG Reserved : 26;
    };
    ULONG AsULONG;
} WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS;

typedef struct _KSYSTEM_TIME
{
    ULONG LowPart;
    LONG High1Time;
    LONG High2Time;
} KSYSTEM_TIME;

typedef struct _IMAGE_DATA_DIRECTORY
{
    ULONG VirtualAddress;
    ULONG Size;
} IMAGE_DATA_DIRECTORY;

typedef struct _MBSTRING
{
    WCHAR szName[15];
    UINT uID;
    UINT uStr;
} MBSTRING, *PMBSTRING;

typedef struct _D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES
{
    UINT FirstChannel;
    UINT SecondChannel;
    UINT ThirdChannel;
    UINT FourthChannel;
} D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES;

typedef struct _Win32PoolHead Win32PoolHead;

struct _Win32PoolHead
{
    ULONGLONG size;
    Win32PoolHead *pPrev;
    Win32PoolHead *pNext;
    VOID **pTrace;
};

typedef struct _HFONT__
{
    INT unused;
} HFONT__;

typedef union _WHEA_ERROR_RECORD_HEADER_FLAGS
{
    struct
    {
        ULONG Recovered : 1;
        ULONG PreviousError : 1;
        ULONG Simulated : 1;
        ULONG Reserved : 29;
    };
    ULONG AsULONG;
} WHEA_ERROR_RECORD_HEADER_FLAGS;

typedef struct _PFNCLIENT
{
    LONGLONG (*pfnScrollBarWndProc)(void);
    LONGLONG (*pfnTitleWndProc)(void);
    LONGLONG (*pfnMenuWndProc)(void);
    LONGLONG (*pfnDesktopWndProc)(void);
    LONGLONG (*pfnDefWindowProc)(void);
    LONGLONG (*pfnMessageWindowProc)(void);
    LONGLONG (*pfnSwitchWindowProc)(void);
    LONGLONG (*pfnButtonWndProc)(void);
    LONGLONG (*pfnComboBoxWndProc)(void);
    LONGLONG (*pfnComboListBoxProc)(void);
    LONGLONG (*pfnDialogWndProc)(void);
    LONGLONG (*pfnEditWndProc)(void);
    LONGLONG (*pfnListBoxWndProc)(void);
    LONGLONG (*pfnMDIClientWndProc)(void);
    LONGLONG (*pfnStaticWndProc)(void);
    LONGLONG (*pfnImeWndProc)(void);
    LONGLONG (*pfnGhostWndProc)(void);
    LONGLONG (*pfnHkINLPCWPSTRUCT)(void);
    LONGLONG (*pfnHkINLPCWPRETSTRUCT)(void);
    LONGLONG (*pfnDispatchHook)(void);
    LONGLONG (*pfnDispatchDefWindowProc)(void);
    LONGLONG (*pfnDispatchMessage)(void);
    LONGLONG (*pfnMDIActivateDlgProc)(void);
} PFNCLIENT, *PPFNCLIENT;

typedef struct _RTL_DYNAMIC_HASH_TABLE
{
    ULONG Flags;
    ULONG Shift;
    ULONG TableSize;
    ULONG Pivot;
    ULONG DivisorMask;
    ULONG NumEntries;
    ULONG NonEmptyBuckets;
    ULONG NumEnumerators;
    VOID *Directory;
} RTL_DYNAMIC_HASH_TABLE;

typedef union _SLIST_HEADER
{
    struct
    {
        ULONGLONG Alignment;
        ULONGLONG Region;
    };
    struct
    {
        ULONGLONG Depth : 16;
        ULONGLONG Sequence : 9;
        ULONGLONG NextEntry : 39;
        ULONGLONG HeaderType : 1;
        ULONGLONG Init : 1;
        ULONGLONG Reserved : 59;
        ULONGLONG Region : 3;
    } Header8;
    struct
    {
        ULONGLONG Depth : 16;
        ULONGLONG Sequence : 48;
        ULONGLONG HeaderType : 1;
        ULONGLONG Init : 1;
        ULONGLONG Reserved : 2;
        ULONGLONG NextEntry : 60;
    } Header16;
    struct
    {
        ULONGLONG Depth : 16;
        ULONGLONG Sequence : 48;
        ULONGLONG HeaderType : 1;
        ULONGLONG Reserved : 3;
        ULONGLONG NextEntry : 60;
    } HeaderX64;
} SLIST_HEADER;

typedef struct _SINGLE_LIST_ENTRY SINGLE_LIST_ENTRY;

struct _SINGLE_LIST_ENTRY
{
    SINGLE_LIST_ENTRY *Next;
};

typedef struct _WNDMSG
{
    UINT maxMsgs;
    UCHAR *abMsgs;
} WNDMSG, *PWNDMSG;

typedef struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME RTL_ACTIVATION_CONTEXT_STACK_FRAME;

struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME
{
    RTL_ACTIVATION_CONTEXT_STACK_FRAME *Previous;
    ACTIVATION_CONTEXT *ActivationContext;
    ULONG Flags;
};

typedef struct _TP_CALLBACK_ENVIRON_V3
{
    ULONG Version;
    TP_POOL *Pool;
    TP_CLEANUP_GROUP *CleanupGroup;
    VOID (*CleanupGroupCancelCallback)(VOID *, VOID *);
    VOID *RaceDll;
    ACTIVATION_CONTEXT *ActivationContext;
    VOID (*FinalizationCallback)(TP_CALLBACK_INSTANCE *, VOID *);
    union
    {
        ULONG Flags;
        struct
        {
            ULONG LongFunction : 1;
            ULONG Persistent : 1;
            ULONG Private : 30;
        } s;
    } u;
    TP_CALLBACK_PRIORITY CallbackPriority;
    ULONG Size;
} TP_CALLBACK_ENVIRON_V3;

typedef struct _HICON__
{
    INT unused;
} HICON__;

typedef struct _DMM_COMMITVIDPNREQUEST_DIAGINFO
{
    INT ClientType : 4;
    INT VidPnChange : 4;
    UCHAR ReclaimClonedTarget : 1;
    UCHAR CleanupAfterFailedCommitVidPn : 1;
    UCHAR ForceAllActiveVidPnModeListInvalidation : 1;
    ULONG ModeChangeRequestId;
} DMM_COMMITVIDPNREQUEST_DIAGINFO;

typedef struct _OBJECT_HANDLE_INFORMATION
{
    ULONG HandleAttributes;
    ULONG GrantedAccess;
} OBJECT_HANDLE_INFORMATION;

typedef struct _TEXTMETRICW
{
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tmInternalLeading;
    LONG tmExternalLeading;
    LONG tmAveCharWidth;
    LONG tmMaxCharWidth;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tmFirstChar;
    WCHAR tmLastChar;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    UCHAR tmItalic;
    UCHAR tmUnderlined;
    UCHAR tmStruckOut;
    UCHAR tmPitchAndFamily;
    UCHAR tmCharSet;
} TEXTMETRICW, *PTEXTMETRICW;

typedef struct _ACCESS_REASONS
{
    ULONG Data[32];
} ACCESS_REASONS;

typedef struct _GENERIC_MAPPING
{
    ULONG GenericRead;
    ULONG GenericWrite;
    ULONG GenericExecute;
    ULONG GenericAll;
} GENERIC_MAPPING;

typedef struct _XSTATE_FEATURE
{
    ULONG Offset;
    ULONG Size;
} XSTATE_FEATURE;

typedef struct _TEB_ACTIVE_FRAME_CONTEXT
{
    ULONG Flags;
    const char *FrameName;
} TEB_ACTIVE_FRAME_CONTEXT;

typedef union _ULARGE_INTEGER
{
    struct
    {
        ULONG LowPart;
        ULONG HighPart;
    };
    struct
    {
        ULONG LowPart;
        ULONG HighPart;
    } u;
    ULONGLONG QuadPart;
} ULARGE_INTEGER;

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT
{
    UINT Identity : 1;
    UINT Rotate90 : 1;
    UINT Rotate180 : 1;
    UINT Rotate270 : 1;
} D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT;

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT
{
    UINT Identity : 1;
    UINT Centered : 1;
    UINT Stretched : 1;
    UINT AspectRatioCenteredMax : 1;
    UINT Custom : 1;
} D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT;

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT
{
    UINT NoProtection : 1;
    UINT MacroVisionApsTrigger : 1;
    UINT MacroVisionFull : 1;
    UINT Reserved : 29;
} D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT;

typedef struct _DXGK_DIAG_HEADER
{
    DXGK_DIAG_TYPE Type;
    UINT Size;
    ULONGLONG LogTimestamp;
    UCHAR ProcessName[16];
    ULONGLONG ThreadId;
    UINT Index;
    UINT WdLogIdx;
} DXGK_DIAG_HEADER;

typedef struct _POOLRECORD
{
    VOID *ExtraData;
    ULONGLONG size;
    VOID *trace[6];
} POOLRECORD, *PPOOLRECORD;

typedef struct _WM_VALUES_STRINGS
{
    CHAR *pszName;
    UCHAR fInternal;
    UCHAR fDefined;
} WM_VALUES_STRINGS;

typedef struct _EVENT_DATA_DESCRIPTOR
{
    ULONGLONG Ptr;
    ULONG Size;
    ULONG Reserved;
} EVENT_DATA_DESCRIPTOR;

typedef struct _KFLOATING_SAVE
{
    ULONG Dummy;
} KFLOATING_SAVE;

typedef struct _EVENT_DESCRIPTOR
{
    USHORT Id;
    UCHAR Version;
    UCHAR Channel;
    UCHAR Level;
    UCHAR Opcode;
    USHORT Task;
    ULONGLONG Keyword;
} EVENT_DESCRIPTOR;

typedef struct _GDI_TEB_BATCH
{
    ULONG Offset;
    ULONGLONG HDC;
    ULONG Buffer[310];
} GDI_TEB_BATCH;

typedef struct _OBJECT_DUMP_CONTROL
{
    VOID *Stream;
    ULONG Detail;
} OBJECT_DUMP_CONTROL;

typedef struct _CLIENT_ID
{
    VOID *UniqueProcess;
    VOID *UniqueThread;
} CLIENT_ID;

typedef struct _PFNCLIENTWORKER
{
    LONGLONG (*pfnButtonWndProc)(void);
    LONGLONG (*pfnComboBoxWndProc)(void);
    LONGLONG (*pfnComboListBoxProc)(void);
    LONGLONG (*pfnDialogWndProc)(void);
    LONGLONG (*pfnEditWndProc)(void);
    LONGLONG (*pfnListBoxWndProc)(void);
    LONGLONG (*pfnMDIClientWndProc)(void);
    LONGLONG (*pfnStaticWndProc)(void);
    LONGLONG (*pfnImeWndProc)(void);
    LONGLONG (*pfnGhostWndProc)(void);
    LONGLONG (*pfnCtfHookProc)(void);
} PFNCLIENTWORKER, *PPFNCLIENTWORKER;

typedef struct _OEMBITMAPINFO
{
    INT x;
    INT y;
    INT cx;
    INT cy;
} OEMBITMAPINFO, *POEMBITMAPINFO;

typedef struct _LIST_ENTRY32
{
    ULONG Flink;
    ULONG Blink;
} LIST_ENTRY32;

typedef struct _DMM_VIDPNSET_SERIALIZATION
{
    UCHAR NumVidPns;
    ULONG VidPnOffset[1];
} DMM_VIDPNSET_SERIALIZATION;

typedef struct _TOUCHINPUT
{
    LONG x;
    LONG y;
    VOID *hSource;
    ULONG dwID;
    ULONG dwFlags;
    ULONG dwMask;
    ULONG dwTime;
    ULONGLONG dwExtraInfo;
    ULONG cxContact;
    ULONG cyContact;
} TOUCHINPUT, *PTOUCHINPUT;

typedef struct _QUAD
{
    union
    {
        LONGLONG UseThisFieldToCopy;
        FLOAT DoNotUseThisField;
    };
} QUAD, *PQUAD;

typedef struct _DMM_MONITOR_SERIALIZATION
{
    ULONG Size;
    UINT VideoPresentTargetId;
    D3DKMDT_MONITOR_ORIENTATION Orientation;
    UCHAR IsSimulatedMonitor;
    UCHAR IsUsingDefaultProfile;
    DMM_MODE_PRUNING_ALGORITHM ModePruningAlgorithm;
    DEVICE_POWER_STATE MonitorPowerState;
    ULONG SourceModeSetOffset;
    ULONG FrequencyRangeSetOffset;
    ULONG DescriptorSetOffset;
    DMM_VIDPN_MONITOR_TYPE MonitorType;
} DMM_MONITOR_SERIALIZATION;

typedef struct _DMM_MONITORDESCRIPTOR_SERIALIZATION
{
    UINT Id;
    D3DKMDT_MONITOR_DESCRIPTOR_TYPE Type;
    D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
    UCHAR Data[128];
} DMM_MONITORDESCRIPTOR_SERIALIZATION;

typedef struct _DMM_VIDPN_SERIALIZATION
{
    ULONG Size;
    UCHAR NumActiveSources;
    ULONG PathsFromSourceSerializationOffsets[1];
} DMM_VIDPN_SERIALIZATION;

typedef struct _PROFILEVALUEINFO
{
    ULONG dwValue;
    UINT uSection;
    const wchar_t *pwszKeyName;
} PROFILEVALUEINFO, *PPROFILEVALUEINFO;

typedef struct _SM_VALUES_STRINGS
{
    CHAR *pszName;
    ULONG ulValue;
    SM_RANGE_TYPES RangeType;
    SM_STORAGE_MODIFIER StorageType;
} SM_VALUES_STRINGS;

typedef struct _VK_VALUES_STRINGS
{
    CHAR *pszMultiNames;
    UCHAR fReserved;
} VK_VALUES_STRINGS;

typedef struct _SLIST_ENTRY SLIST_ENTRY;

struct _SLIST_ENTRY
{
    SLIST_ENTRY *Next;
};

typedef struct _IO_STATUS_BLOCK32
{
    LONG Status;
    ULONG Information;
} IO_STATUS_BLOCK32;

typedef struct _TXN_PARAMETER_BLOCK
{
    USHORT Length;
    USHORT TxFsContext;
    VOID *TransactionObject;
} TXN_PARAMETER_BLOCK;

typedef struct _DMM_COFUNCPATHSMODALITY_SERIALIZATION
{
    UCHAR NumPathsFromSource;
    ULONG PathAndTargetModeSetOffset[1];
} DMM_COFUNCPATHSMODALITY_SERIALIZATION;

typedef struct _LIST_ENTRY64
{
    ULONGLONG Flink;
    ULONGLONG Blink;
} LIST_ENTRY64;

typedef struct _CONTEXT32_UPDATE
{
    ULONG NumberEntries;
} CONTEXT32_UPDATE;

typedef struct _DMM_COMMITVIDPNREQUESTSET_SERIALIZATION
{
    UCHAR NumCommitVidPnRequests;
    ULONG CommitVidPnRequestOffset[1];
} DMM_COMMITVIDPNREQUESTSET_SERIALIZATION;

typedef struct _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR
{
    ULONG SectionOffset;
    ULONG SectionLength;
    WHEA_REVISION Revision;
    WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS ValidBits;
    UCHAR Reserved;
    WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS Flags;
    GUID SectionType;
    GUID FRUId;
    WHEA_ERROR_SEVERITY SectionSeverity;
    CHAR FRUText[20];
} WHEA_ERROR_RECORD_SECTION_DESCRIPTOR;

typedef struct _SCATTER_GATHER_ELEMENT
{
    LARGE_INTEGER Address;
    ULONG Length;
    ULONGLONG Reserved;
} SCATTER_GATHER_ELEMENT;

typedef struct _LUID_AND_ATTRIBUTES
{
    LUID Luid;
    ULONG Attributes;
} LUID_AND_ATTRIBUTES;

typedef struct _KSPECIAL_REGISTERS
{
    ULONGLONG Cr0;
    ULONGLONG Cr2;
    ULONGLONG Cr3;
    ULONGLONG Cr4;
    ULONGLONG KernelDr0;
    ULONGLONG KernelDr1;
    ULONGLONG KernelDr2;
    ULONGLONG KernelDr3;
    ULONGLONG KernelDr6;
    ULONGLONG KernelDr7;
    KDESCRIPTOR Gdtr;
    KDESCRIPTOR Idtr;
    USHORT Tr;
    USHORT Ldtr;
    ULONG MxCsr;
    ULONGLONG DebugControl;
    ULONGLONG LastBranchToRip;
    ULONGLONG LastBranchFromRip;
    ULONGLONG LastExceptionToRip;
    ULONGLONG LastExceptionFromRip;
    ULONGLONG Cr8;
    ULONGLONG MsrGsBase;
    ULONGLONG MsrGsSwap;
    ULONGLONG MsrStar;
    ULONGLONG MsrLStar;
    ULONGLONG MsrCStar;
    ULONGLONG MsrSyscallMask;
} KSPECIAL_REGISTERS;

typedef struct _XSAVE_FORMAT
{
    USHORT ControlWord;
    USHORT StatusWord;
    UCHAR TagWord;
    UCHAR Reserved1;
    USHORT ErrorOpcode;
    ULONG ErrorOffset;
    USHORT ErrorSelector;
    USHORT Reserved2;
    ULONG DataOffset;
    USHORT DataSelector;
    USHORT Reserved3;
    ULONG MxCsr;
    ULONG MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    UCHAR Reserved4[96];
} XSAVE_FORMAT;

typedef struct _CURDIR
{
    UNICODE_STRING DosPath;
    VOID *Handle;
} CURDIR, *PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
    USHORT Flags;
    USHORT Length;
    ULONG TimeStamp;
    STRING DosPath;
} RTL_DRIVE_LETTER_CURDIR;

typedef struct _D3DKMDT_VIDEO_SIGNAL_INFO
{
    D3DKMDT_VIDEO_SIGNAL_STANDARD VideoStandard;
    D3DKMDT_2DREGION TotalSize;
    D3DKMDT_2DREGION ActiveSize;
    D3DDDI_RATIONAL VSyncFreq;
    D3DDDI_RATIONAL HSyncFreq;
    ULONGLONG PixelRate;
    D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering;
} D3DKMDT_VIDEO_SIGNAL_INFO;

typedef struct _OBJECT_ATTRIBUTES
{
    ULONG Length;
    VOID *RootDirectory;
    UNICODE_STRING *ObjectName;
    ULONG Attributes;
    VOID *SecurityDescriptor;
    VOID *SecurityQualityOfService;
} OBJECT_ATTRIBUTES;

typedef struct _D3DKMDT_GRAPHICS_RENDERING_FORMAT
{
    D3DKMDT_2DREGION PrimSurfSize;
    D3DKMDT_2DREGION VisibleRegionSize;
    ULONG Stride;
    D3DDDIFORMAT PixelFormat;
    D3DKMDT_COLOR_BASIS ColorBasis;
    D3DKMDT_PIXEL_VALUE_ACCESS_MODE PixelValueAccessMode;
} D3DKMDT_GRAPHICS_RENDERING_FORMAT;

typedef struct _VK_TO_FUNCTION_TABLE
{
    UCHAR Vk;
    UCHAR NLSFEProcType;
    UCHAR NLSFEProcCurrent;
    UCHAR NLSFEProcSwitch;
    VK_FUNCTION_PARAM NLSFEProc[8];
    VK_FUNCTION_PARAM NLSFEProcAlt[8];
} VK_TO_FUNCTION_TABLE;

typedef struct _RTL_CRITICAL_SECTION_DEBUG RTL_CRITICAL_SECTION_DEBUG;
typedef struct _RTL_CRITICAL_SECTION RTL_CRITICAL_SECTION;

struct _RTL_CRITICAL_SECTION_DEBUG
{
    USHORT Type;
    USHORT CreatorBackTraceIndex;
    RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    ULONG EntryCount;
    ULONG ContentionCount;
    ULONG Flags;
    USHORT CreatorBackTraceIndexHigh;
    USHORT SpareUSHORT;
};
struct _RTL_CRITICAL_SECTION
{
    RTL_CRITICAL_SECTION_DEBUG *DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    VOID *OwningThread;
    VOID *LockSemaphore;
    ULONGLONG SpinCount;
};

typedef struct _MONITOR MONITOR, *PMONITOR;

struct _MONITOR
{
    HEAD head;
    PMONITOR pMonitorNext;
    ULONG dwMONFlags;
    RECT rcMonitorReal;
    RECT rcWorkReal;
    HRGN__ *hrgnMonitorReal;
    SHORT Spare0;
    SHORT cWndStack;
    VOID *hDev;
    VOID *hDevReal;
    UCHAR DockTargets[7][4];
    PMONITOR Flink;
    PMONITOR Blink;
};

typedef struct _D3DKMDT_FREQUENCY_RANGE
{
    D3DDDI_RATIONAL MinVSyncFreq;
    D3DDDI_RATIONAL MaxVSyncFreq;
    D3DDDI_RATIONAL MinHSyncFreq;
    D3DDDI_RATIONAL MaxHSyncFreq;
} D3DKMDT_FREQUENCY_RANGE;

typedef struct _IMAGE_OPTIONAL_HEADER64
{
    USHORT Magic;
    UCHAR MajorLinkerVersion;
    UCHAR MinorLinkerVersion;
    ULONG SizeOfCode;
    ULONG SizeOfInitializedData;
    ULONG SizeOfUninitializedData;
    ULONG AddressOfEntryPoint;
    ULONG BaseOfCode;
    ULONGLONG ImageBase;
    ULONG SectionAlignment;
    ULONG FileAlignment;
    USHORT MajorOperatingSystemVersion;
    USHORT MinorOperatingSystemVersion;
    USHORT MajorImageVersion;
    USHORT MinorImageVersion;
    USHORT MajorSubsystemVersion;
    USHORT MinorSubsystemVersion;
    ULONG Win32VersionValue;
    ULONG SizeOfImage;
    ULONG SizeOfHeaders;
    ULONG CheckSum;
    USHORT Subsystem;
    USHORT DllCharacteristics;
    ULONGLONG SizeOfStackReserve;
    ULONGLONG SizeOfStackCommit;
    ULONGLONG SizeOfHeapReserve;
    ULONGLONG SizeOfHeapCommit;
    ULONG LoaderFlags;
    ULONG NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER64;

typedef struct _DMM_COMMITVIDPNREQUEST_SERIALIZATION
{
    UINT AffectedVidPnSourceId;
    DMM_COMMITVIDPNREQUEST_DIAGINFO RequestDiagInfo;
    DMM_VIDPN_SERIALIZATION VidPnSerialization;
} DMM_COMMITVIDPNREQUEST_SERIALIZATION;

typedef union _UAHMENUITEMMETRICS
{
    SIZE rgsizeBar[2];
    SIZE rgsizePopup[4];
} UAHMENUITEMMETRICS, *PUAHMENUITEMMETRICS;

typedef struct _D3DDDI_GAMMA_RAMP_DXGI_1
{
    D3DDDI_DXGI_RGB Scale;
    D3DDDI_DXGI_RGB Offset;
    D3DDDI_DXGI_RGB GammaCurve[1025];
} D3DDDI_GAMMA_RAMP_DXGI_1;

typedef struct _DPISERVERINFO
{
    INT gclBorder;
    HFONT__ *hCaptionFont;
    HFONT__ *hMsgFont;
    INT cxMsgFontChar;
    INT cyMsgFontChar;
    UINT wMaxBtnSize;
} DPISERVERINFO, *PDPISERVERINFO;

typedef struct _SBINFO
{
    INT WSBflags;
    SBDATA Horz;
    SBDATA Vert;
} SBINFO, *PSBINFO;

typedef struct _PROPLIST
{
    UINT cEntries;
    UINT iFirstFree;
    PROP aprop[1];
} PROPLIST, *PPROPLIST;

typedef struct _GENERAL_LOOKASIDE_POOL GENERAL_LOOKASIDE_POOL;
typedef struct _LOOKASIDE_LIST_EX LOOKASIDE_LIST_EX;

struct _GENERAL_LOOKASIDE_POOL
{
    union
    {
        SLIST_HEADER ListHead;
        SINGLE_LIST_ENTRY SingleListHead;
    };
    USHORT Depth;
    USHORT MaximumDepth;
    ULONG TotalAllocates;
    union
    {
        ULONG AllocateMisses;
        ULONG AllocateHits;
    };
    ULONG TotalFrees;
    union
    {
        ULONG FreeMisses;
        ULONG FreeHits;
    };
    POOL_TYPE Type;
    ULONG Tag;
    ULONG Size;
    union
    {
        VOID *(*AllocateEx)(POOL_TYPE, ULONGLONG, ULONG, LOOKASIDE_LIST_EX *);
        VOID *(*Allocate)(POOL_TYPE, ULONGLONG, ULONG);
    };
    union
    {
        VOID (*FreeEx)(VOID *, LOOKASIDE_LIST_EX *);
        VOID (*Free)(VOID *);
    };
    LIST_ENTRY ListEntry;
    ULONG LastTotalAllocates;
    union
    {
        ULONG LastAllocateMisses;
        ULONG LastAllocateHits;
    };
    ULONG Future[2];
};
struct _LOOKASIDE_LIST_EX
{
    GENERAL_LOOKASIDE_POOL L;
};

typedef struct _MSG
{
    HWND__ *hwnd;
    UINT message;
    ULONGLONG wParam;
    LONGLONG lParam;
    ULONG time;
    POINT pt;
} MSG, *PMSG;

typedef struct _RTL_DYNAMIC_HASH_TABLE_ENTRY
{
    LIST_ENTRY Linkage;
    ULONGLONG Signature;
} RTL_DYNAMIC_HASH_TABLE_ENTRY;

typedef struct _DISPATCHER_HEADER
{
    union
    {
        struct
        {
            UCHAR Type;
            union
            {
                UCHAR TimerControlFlags;
                struct
                {
                    UCHAR Absolute : 1;
                    UCHAR Coalescable : 1;
                    UCHAR KeepShifting : 1;
                    UCHAR EncodedTolerableDelay : 5;
                };
                UCHAR Abandoned;
                UCHAR Signalling;
            };
            union
            {
                UCHAR ThreadControlFlags;
                struct
                {
                    UCHAR CpuThrottled : 1;
                    UCHAR CycleProfiling : 1;
                    UCHAR CounterProfiling : 1;
                    UCHAR Reserved : 5;
                };
                UCHAR Hand;
                UCHAR Size;
            };
            union
            {
                UCHAR TimerMiscFlags;
                struct
                {
                    UCHAR Index : 6;
                    UCHAR Inserted : 1;
                    volatile unsigned char Expired : 1;
                };
                UCHAR DebugActive;
                struct
                {
                    UCHAR ActiveDR7 : 1;
                    UCHAR Instrumented : 1;
                    UCHAR Reserved2 : 4;
                    UCHAR UmsScheduled : 1;
                    UCHAR UmsPrimary : 1;
                };
                UCHAR DpcActive;
            };
        };
        volatile long Lock;
    };
    LONG SignalState;
    LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER;

typedef struct _TP_NBQ_GUARD
{
    LIST_ENTRY GuardLinks;
    VOID *Guards[2];
} TP_NBQ_GUARD;

typedef struct _IMEINFOEX
{
    HKL__ *hkl;
    IMEINFO ImeInfo;
    WCHAR wszUIClass[16];
    ULONG fdwInitConvMode;
    INT fInitOpen;
    INT fLoadFlag;
    ULONG dwProdVersion;
    ULONG dwImeWinVersion;
    WCHAR wszImeDescription[50];
    WCHAR wszImeFile[80];
    INT fSysWow64Only : 1;
    INT fCUASLayer : 1;
} IMEINFOEX, *PIMEINFOEX;

typedef struct _MODIFIERS
{
    VK_TO_BIT *pVkToBit;
    USHORT wMaxModBits;
    UCHAR ModNumber[0];
} MODIFIERS, *PMODIFIERS;

typedef struct _HANDLEENTRY
{
    PHEAD phead;
    VOID *pOwner;
    UCHAR bType;
    UCHAR bFlags;
    USHORT wUniq;
} HANDLEENTRY, *PHANDLEENTRY;

typedef struct _VK_TO_WCHAR_TABLE
{
    VK_TO_WCHARS1 *pVkToWchars;
    UCHAR nModifications;
    UCHAR cbSize;
} VK_TO_WCHAR_TABLE;

typedef struct _TEB_ACTIVE_FRAME TEB_ACTIVE_FRAME;

struct _TEB_ACTIVE_FRAME
{
    ULONG Flags;
    TEB_ACTIVE_FRAME *Previous;
    TEB_ACTIVE_FRAME_CONTEXT *Context;
};

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION
{
    D3DKMDT_VIDPN_PRESENT_PATH_SCALING Scaling;
    D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT ScalingSupport;
    D3DKMDT_VIDPN_PRESENT_PATH_ROTATION Rotation;
    D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT RotationSupport;
} D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION;

typedef struct _DXGK_DIAG_CODE_POINT_PACKET
{
    DXGK_DIAG_HEADER Header;
    DXGK_DIAG_CODE_POINT_TYPE CodePointType;
    UINT Param1;
    UINT Param2;
    UINT Param3;
} DXGK_DIAG_CODE_POINT_PACKET;

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION
{
    D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE CopyProtectionType;
    UINT APSTriggerBits;
    UCHAR OEMCopyProtection[256];
    D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT CopyProtectionSupport;
} D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION;

typedef struct _RTL_AVL_TABLE RTL_AVL_TABLE;

struct _RTL_AVL_TABLE
{
    RTL_BALANCED_LINKS BalancedRoot;
    VOID *OrderedPointer;
    ULONG WhichOrderedElement;
    ULONG NumberGenericTableElements;
    ULONG DepthOfTree;
    RTL_BALANCED_LINKS *RestartKey;
    ULONG DeleteCount;
    RTL_GENERIC_COMPARE_RESULTS (*CompareRoutine)(RTL_AVL_TABLE *, VOID *, VOID *);
    VOID *(*AllocateRoutine)(RTL_AVL_TABLE *, ULONG);
    VOID (*FreeRoutine)(RTL_AVL_TABLE *, VOID *);
    VOID *TableContext;
};

typedef struct _PEB_LDR_DATA
{
    ULONG Length;
    UCHAR Initialized;
    VOID *SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    VOID *EntryInProgress;
    UCHAR ShutdownInProgress;
    VOID *ShutdownThreadId;
} PEB_LDR_DATA;

typedef struct _HID_TLC_INFO
{
    LIST_ENTRY link;
    USHORT usUsagePage;
    USHORT usUsage;
    UINT cDevices;
    UINT cDirectRequest;
    UINT cUsagePageRequest;
    UINT cExcludeRequest;
    UINT cExcludeOrphaned;
} HID_TLC_INFO;

typedef struct _HID_PAGEONLY_REQUEST
{
    LIST_ENTRY link;
    USHORT usUsagePage;
    UINT cRefCount;
} HID_PAGEONLY_REQUEST;

typedef struct _CONSOLE_CARET_INFO
{
    HWND__ *hwnd;
    RECT rc;
} CONSOLE_CARET_INFO;

typedef struct _Win32AllocStats
{
    ULONGLONG dwMaxMem;
    ULONGLONG dwCrtMem;
    ULONG dwMaxAlloc;
    ULONG dwCrtAlloc;
    Win32PoolHead *pHead;
} Win32AllocStats;

typedef struct _KDEVICE_QUEUE
{
    SHORT Type;
    SHORT Size;
    LIST_ENTRY DeviceListHead;
    ULONGLONG Lock;
    union
    {
        UCHAR Busy;
        LONGLONG Reserved : 8;
    };
    LONGLONG Hint : 56;
} KDEVICE_QUEUE;

typedef struct _CM_PARTIAL_RESOURCE_DESCRIPTOR
{
    UCHAR Type;
    UCHAR ShareDisposition;
    USHORT Flags;
    union
    {
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length;
        } Generic;
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length;
        } Port;
        struct
        {
            USHORT Level;
            USHORT Group;
            ULONG Vector;
            ULONGLONG Affinity;
        } Interrupt;
        struct
        {
            union
            {
                struct
                {
                    USHORT Group;
                    USHORT MessageCount;
                    ULONG Vector;
                    ULONGLONG Affinity;
                } Raw;
                struct
                {
                    USHORT Level;
                    USHORT Group;
                    ULONG Vector;
                    ULONGLONG Affinity;
                } Translated;
            };
        } MessageInterrupt;
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length;
        } Memory;
        struct
        {
            ULONG Channel;
            ULONG Port;
            ULONG Reserved1;
        } Dma;
        struct
        {
            ULONG Data[3];
        } DevicePrivate;
        struct
        {
            ULONG Start;
            ULONG Length;
            ULONG Reserved;
        } BusNumber;
        struct
        {
            ULONG DataSize;
            ULONG Reserved1;
            ULONG Reserved2;
        } DeviceSpecificData;
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length40;
        } Memory40;
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length48;
        } Memory48;
        struct
        {
            LARGE_INTEGER Start;
            ULONG Length64;
        } Memory64;
    } u;
} CM_PARTIAL_RESOURCE_DESCRIPTOR;

typedef struct _XSTATE_CONFIGURATION
{
    ULONGLONG EnabledFeatures;
    ULONG Size;
    ULONG OptimizedSave : 1;
    XSTATE_FEATURE Features[64];
} XSTATE_CONFIGURATION;

typedef struct _WHEA_ERROR_PACKET_V2
{
    ULONG Signature;
    ULONG Version;
    ULONG Length;
    WHEA_ERROR_PACKET_FLAGS Flags;
    WHEA_ERROR_TYPE ErrorType;
    WHEA_ERROR_SEVERITY ErrorSeverity;
    ULONG ErrorSourceId;
    WHEA_ERROR_SOURCE_TYPE ErrorSourceType;
    GUID NotifyType;
    ULONGLONG Context;
    WHEA_ERROR_PACKET_DATA_FORMAT DataFormat;
    ULONG Reserved1;
    ULONG DataOffset;
    ULONG DataLength;
    ULONG PshedDataOffset;
    ULONG PshedDataLength;
} WHEA_ERROR_PACKET_V2;

typedef struct _W32THREAD
{
    ETHREAD *pEThread;
    ULONG RefCount;
    PTL ptlW32;
    VOID *pgdiDcattr;
    VOID *pgdiBrushAttr;
    VOID *pUMPDObjs;
    VOID *pUMPDHeap;
    VOID *pUMPDObj;
    VOID *pProxyPort;
    VOID *pClientID;
    LIST_ENTRY GdiTmpTgoList;
    ULONG pRBRecursionCount;
    ULONG pNonRBRecursionCount;
    TLSPRITESTATE tlSpriteState;
    VOID *pSpriteState;
    VOID *pDevHTInfo;
    ULONG ulDevHTInfoUniqueness;
    VOID *pdcoAA;
    VOID *pdcoRender;
    VOID *pdcoSrc;
    UCHAR bEnableEngUpdateDeviceSurface;
    UCHAR bIncludeSprites;
    ULONG ulWindowSystemRendering;
    ULONG iVisRgnUniqueness;
} W32THREAD, *PW32THREAD;

typedef union _WHEA_TIMESTAMP
{
    struct
    {
        ULONGLONG Seconds : 8;
        ULONGLONG Minutes : 8;
        ULONGLONG Hours : 8;
        ULONGLONG Precise : 1;
        ULONGLONG Reserved : 7;
        ULONGLONG Day : 8;
        ULONGLONG Month : 8;
        ULONGLONG Year : 8;
        ULONGLONG Century : 8;
    };
    LARGE_INTEGER AsLARGE_INTEGER;
} WHEA_TIMESTAMP;

typedef struct _EX_PUSH_LOCK_CACHE_AWARE
{
    EX_PUSH_LOCK *Locks[1];
} EX_PUSH_LOCK_CACHE_AWARE;

typedef struct _RTL_DYNAMIC_HASH_TABLE_CONTEXT
{
    LIST_ENTRY *ChainHead;
    LIST_ENTRY *PrevLinkage;
    ULONGLONG Signature;
} RTL_DYNAMIC_HASH_TABLE_CONTEXT;

typedef struct _TP_DIRECT TP_DIRECT;

struct _TP_DIRECT
{
    VOID (*Callback)(TP_CALLBACK_INSTANCE *, TP_DIRECT *, VOID *, IO_STATUS_BLOCK *);
    ULONG NumaNode;
    UCHAR IdealProcessor;
};

typedef struct _DMM_MONITORDESCRIPTORSET_SERIALIZATION
{
    UCHAR NumDescriptors;
    DMM_MONITORDESCRIPTOR_SERIALIZATION DescriptorSerialization[1];
} DMM_MONITORDESCRIPTORSET_SERIALIZATION;

typedef struct _KDPC KDPC, *PKDPC;

struct _KDPC
{
    UCHAR Type;
    UCHAR Importance;
    volatile unsigned short Number;
    LIST_ENTRY DpcListEntry;
    VOID (*DeferredRoutine)(PKDPC, VOID *, VOID *, VOID *);
    VOID *DeferredContext;
    VOID *SystemArgument1;
    VOID *SystemArgument2;
    VOID *DpcData;
};

typedef struct _KDEVICE_QUEUE_ENTRY
{
    LIST_ENTRY DeviceListEntry;
    ULONG SortKey;
    UCHAR Inserted;
} KDEVICE_QUEUE_ENTRY;

typedef struct _OBJECT_NAME_INFORMATION
{
    UNICODE_STRING Name;
} OBJECT_NAME_INFORMATION;

typedef struct _FILE_NETWORK_OPEN_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG FileAttributes;
} FILE_NETWORK_OPEN_INFORMATION;

typedef struct _FILE_STANDARD_INFORMATION
{
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG NumberOfLinks;
    UCHAR DeletePending;
    UCHAR Directory;
} FILE_STANDARD_INFORMATION;

typedef struct _FILE_BASIC_INFORMATION
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    ULONG FileAttributes;
} FILE_BASIC_INFORMATION;

typedef struct _MAILSLOT_CREATE_PARAMETERS
{
    ULONG MailslotQuota;
    ULONG MaximumMessageSize;
    LARGE_INTEGER ReadTimeout;
    UCHAR TimeoutSpecified;
} MAILSLOT_CREATE_PARAMETERS;

typedef struct _NAMED_PIPE_CREATE_PARAMETERS
{
    ULONG NamedPipeType;
    ULONG ReadMode;
    ULONG CompletionMode;
    ULONG MaximumInstances;
    ULONG InboundQuota;
    ULONG OutboundQuota;
    LARGE_INTEGER DefaultTimeout;
    UCHAR TimeoutSpecified;
} NAMED_PIPE_CREATE_PARAMETERS;

typedef struct _IO_DRIVER_CREATE_CONTEXT
{
    SHORT Size;
    ECP_LIST *ExtraCreateParameter;
    VOID *DeviceObjectHint;
    TXN_PARAMETER_BLOCK *TxnParameters;
} IO_DRIVER_CREATE_CONTEXT;

typedef struct _IO_RESOURCE_DESCRIPTOR
{
    UCHAR Option;
    UCHAR Type;
    UCHAR ShareDisposition;
    UCHAR Spare1;
    USHORT Flags;
    USHORT Spare2;
    union
    {
        struct
        {
            ULONG Length;
            ULONG Alignment;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Port;
        struct
        {
            ULONG Length;
            ULONG Alignment;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Memory;
        struct
        {
            ULONG MinimumVector;
            ULONG MaximumVector;
            USHORT AffinityPolicy;
            USHORT Group;
            IRQ_PRIORITY PriorityPolicy;
            ULONGLONG TargetedProcessors;
        } Interrupt;
        struct
        {
            ULONG MinimumChannel;
            ULONG MaximumChannel;
        } Dma;
        struct
        {
            ULONG Length;
            ULONG Alignment;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Generic;
        struct
        {
            ULONG Data[3];
        } DevicePrivate;
        struct
        {
            ULONG Length;
            ULONG MinBusNumber;
            ULONG MaxBusNumber;
            ULONG Reserved;
        } BusNumber;
        struct
        {
            ULONG Priority;
            ULONG Reserved1;
            ULONG Reserved2;
        } ConfigData;
        struct
        {
            ULONG Length40;
            ULONG Alignment40;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Memory40;
        struct
        {
            ULONG Length48;
            ULONG Alignment48;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Memory48;
        struct
        {
            ULONG Length64;
            ULONG Alignment64;
            LARGE_INTEGER MinimumAddress;
            LARGE_INTEGER MaximumAddress;
        } Memory64;
    } u;
} IO_RESOURCE_DESCRIPTOR;

typedef struct _ACTIVATION_CONTEXT_STACK
{
    RTL_ACTIVATION_CONTEXT_STACK_FRAME *ActiveFrame;
    LIST_ENTRY FrameListCache;
    ULONG Flags;
    ULONG NextCookieSequenceNumber;
    ULONG StackId;
} ACTIVATION_CONTEXT_STACK;

typedef struct _KAPC KAPC, *PKAPC;

struct _KAPC
{
    UCHAR Type;
    UCHAR SpareByte0;
    UCHAR Size;
    UCHAR SpareByte1;
    ULONG SpareLong0;
    KTHREAD *Thread;
    LIST_ENTRY ApcListEntry;
    VOID (*KernelRoutine)(PKAPC, VOID (**)(VOID *, VOID *, VOID *), VOID **, VOID **, VOID **);
    VOID (*RundownRoutine)(PKAPC);
    VOID (*NormalRoutine)(VOID *, VOID *, VOID *);
    VOID *NormalContext;
    VOID *SystemArgument1;
    VOID *SystemArgument2;
    CHAR ApcStateIndex;
    CHAR ApcMode;
    UCHAR Inserted;
};

typedef struct _SCATTER_GATHER_LIST
{
    ULONG NumberOfElements;
    ULONGLONG Reserved;
    SCATTER_GATHER_ELEMENT Elements[0];
} SCATTER_GATHER_LIST;

typedef struct _INITIAL_PRIVILEGE_SET
{
    ULONG PrivilegeCount;
    ULONG Control;
    LUID_AND_ATTRIBUTES Privilege[3];
} INITIAL_PRIVILEGE_SET;

typedef struct _D3DKMDT_GAMMA_RAMP
{
    D3DDDI_GAMMARAMP_TYPE Type;
    ULONGLONG DataSize;
    union
    {
        D3DDDI_GAMMA_RAMP_RGB256x3x16 *pRgb256x3x16;
        D3DDDI_GAMMA_RAMP_DXGI_1 *pDxgi1;
        VOID *pRaw;
    } Data;
} D3DKMDT_GAMMA_RAMP;

typedef struct _CONTEXT
{
    ULONGLONG P1Home;
    ULONGLONG P2Home;
    ULONGLONG P3Home;
    ULONGLONG P4Home;
    ULONGLONG P5Home;
    ULONGLONG P6Home;
    ULONG ContextFlags;
    ULONG MxCsr;
    USHORT SegCs;
    USHORT SegDs;
    USHORT SegEs;
    USHORT SegFs;
    USHORT SegGs;
    USHORT SegSs;
    ULONG EFlags;
    ULONGLONG Dr0;
    ULONGLONG Dr1;
    ULONGLONG Dr2;
    ULONGLONG Dr3;
    ULONGLONG Dr6;
    ULONGLONG Dr7;
    ULONGLONG Rax;
    ULONGLONG Rcx;
    ULONGLONG Rdx;
    ULONGLONG Rbx;
    ULONGLONG Rsp;
    ULONGLONG Rbp;
    ULONGLONG Rsi;
    ULONGLONG Rdi;
    ULONGLONG R8;
    ULONGLONG R9;
    ULONGLONG R10;
    ULONGLONG R11;
    ULONGLONG R12;
    ULONGLONG R13;
    ULONGLONG R14;
    ULONGLONG R15;
    ULONGLONG Rip;
    union
    {
        XSAVE_FORMAT FltSave;
        struct
        {
            M128A Header[2];
            M128A Legacy[8];
            M128A Xmm0;
            M128A Xmm1;
            M128A Xmm2;
            M128A Xmm3;
            M128A Xmm4;
            M128A Xmm5;
            M128A Xmm6;
            M128A Xmm7;
            M128A Xmm8;
            M128A Xmm9;
            M128A Xmm10;
            M128A Xmm11;
            M128A Xmm12;
            M128A Xmm13;
            M128A Xmm14;
            M128A Xmm15;
        };
    };
    M128A VectorRegister[26];
    ULONGLONG VectorControl;
    ULONGLONG DebugControl;
    ULONGLONG LastBranchToRip;
    ULONGLONG LastBranchFromRip;
    ULONGLONG LastExceptionToRip;
    ULONGLONG LastExceptionFromRip;
} CONTEXT, *PCONTEXT;

typedef struct _D3DKMDT_VIDPN_TARGET_MODE
{
    UINT Id;
    D3DKMDT_VIDEO_SIGNAL_INFO VideoSignalInfo;
    D3DKMDT_MODE_PREFERENCE Preference;
} D3DKMDT_VIDPN_TARGET_MODE;

typedef struct _D3DKMDT_MONITOR_FREQUENCY_RANGE
{
    D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
    D3DKMDT_FREQUENCY_RANGE RangeLimits;
    D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT ConstraintType;
    union
    {
        D3DKMDT_2DREGION ActiveSize;
        ULONGLONG MaxPixelRate;
    } Constraint;
} D3DKMDT_MONITOR_FREQUENCY_RANGE;

typedef struct _IMAGE_NT_HEADERS64
{
    ULONG Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64;

typedef struct _RTL_DYNAMIC_HASH_TABLE_ENUMERATOR
{
    RTL_DYNAMIC_HASH_TABLE_ENTRY HashEntry;
    LIST_ENTRY *ChainHead;
    ULONG BucketIndex;
} RTL_DYNAMIC_HASH_TABLE_ENUMERATOR;

typedef struct _KEVENT
{
    DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT;

typedef struct _TP_TASK_CALLBACKS TP_TASK_CALLBACKS;
typedef struct _TP_TASK TP_TASK;

struct _TP_TASK_CALLBACKS
{
    VOID (*ExecuteCallback)(TP_CALLBACK_INSTANCE *, TP_TASK *);
    VOID (*Unposted)(TP_TASK *, TP_POOL *);
};
struct _TP_TASK
{
    TP_TASK_CALLBACKS *Callbacks;
    ULONG NumaNode;
    UCHAR IdealProcessor;
    TP_NBQ_GUARD PostGuard;
    VOID *NBQNode;
};

typedef struct _GENERAL_LOOKASIDE
{
    union
    {
        SLIST_HEADER ListHead;
        SINGLE_LIST_ENTRY SingleListHead;
    };
    USHORT Depth;
    USHORT MaximumDepth;
    ULONG TotalAllocates;
    union
    {
        ULONG AllocateMisses;
        ULONG AllocateHits;
    };
    ULONG TotalFrees;
    union
    {
        ULONG FreeMisses;
        ULONG FreeHits;
    };
    POOL_TYPE Type;
    ULONG Tag;
    ULONG Size;
    union
    {
        VOID *(*AllocateEx)(POOL_TYPE, ULONGLONG, ULONG, LOOKASIDE_LIST_EX *);
        VOID *(*Allocate)(POOL_TYPE, ULONGLONG, ULONG);
    };
    union
    {
        VOID (*FreeEx)(VOID *, LOOKASIDE_LIST_EX *);
        VOID (*Free)(VOID *);
    };
    LIST_ENTRY ListEntry;
    ULONG LastTotalAllocates;
    union
    {
        ULONG LastAllocateMisses;
        ULONG LastAllocateHits;
    };
    ULONG Future[2];
} GENERAL_LOOKASIDE;

typedef struct _KbdLayer
{
    PMODIFIERS pCharModifiers;
    VK_TO_WCHAR_TABLE *pVkToWcharTable;
    PDEADKEY pDeadKey;
    VSC_LPWSTR *pKeyNames;
    VSC_LPWSTR *pKeyNamesExt;
    USHORT **pKeyNamesDead;
    USHORT *pusVSCtoVK;
    UCHAR bMaxVSCtoVK;
    VSC_VK *pVSCtoVK_E0;
    VSC_VK *pVSCtoVK_E1;
    ULONG fLocaleFlags;
    UCHAR nLgMax;
    UCHAR cbLgEntry;
    PLIGATURE1 pLigature;
    ULONG dwType;
    ULONG dwSubType;
} KbdLayer;

typedef struct _KbdNlsLayer
{
    USHORT OEMIdentifier;
    USHORT LayoutInformation;
    UINT NumOfVkToF;
    VK_TO_FUNCTION_TABLE *pVkToF;
    INT NumOfMouseVKey;
    USHORT *pusMouseVKey;
} KbdNlsLayer;

typedef struct _RTL_USER_PROCESS_PARAMETERS
{
    ULONG MaximumLength;
    ULONG Length;
    ULONG Flags;
    ULONG DebugFlags;
    VOID *ConsoleHandle;
    ULONG ConsoleFlags;
    VOID *StandardInput;
    VOID *StandardOutput;
    VOID *StandardError;
    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    VOID *Environment;
    ULONG StartingX;
    ULONG StartingY;
    ULONG CountX;
    ULONG CountY;
    ULONG CountCharsX;
    ULONG CountCharsY;
    ULONG FillAttribute;
    ULONG WindowFlags;
    ULONG ShowWindowFlags;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING DesktopInfo;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeData;
    RTL_DRIVE_LETTER_CURDIR CurrentDirectores[32];
    volatile unsigned __int64 EnvironmentSize;
    volatile unsigned __int64 EnvironmentVersion;
} RTL_USER_PROCESS_PARAMETERS;

typedef struct _CM_PARTIAL_RESOURCE_LIST
{
    USHORT Version;
    USHORT Revision;
    ULONG Count;
    CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[1];
} CM_PARTIAL_RESOURCE_LIST;

typedef struct _WHEA_ERROR_RECORD_HEADER
{
    ULONG Signature;
    WHEA_REVISION Revision;
    ULONG SignatureEnd;
    USHORT SectionCount;
    WHEA_ERROR_SEVERITY Severity;
    WHEA_ERROR_RECORD_HEADER_VALIDBITS ValidBits;
    ULONG Length;
    WHEA_TIMESTAMP Timestamp;
    GUID PlatformId;
    GUID PartitionId;
    GUID CreatorId;
    GUID NotifyType;
    ULONGLONG RecordId;
    WHEA_ERROR_RECORD_HEADER_FLAGS Flags;
    WHEA_PERSISTENCE_INFO PersistenceInfo;
    UCHAR Reserved[12];
} WHEA_ERROR_RECORD_HEADER;

typedef struct _KSEMAPHORE
{
    DISPATCHER_HEADER Header;
    LONG Limit;
} KSEMAPHORE, *PKSEMAPHORE;

typedef struct _D3DKMDT_VIDPN_SOURCE_MODE
{
    UINT Id;
    D3DKMDT_VIDPN_SOURCE_MODE_TYPE Type;
    union
    {
        D3DKMDT_GRAPHICS_RENDERING_FORMAT Graphics;
        D3DKMDT_TEXT_RENDERING_FORMAT Text;
    } Format;
} D3DKMDT_VIDPN_SOURCE_MODE;

typedef struct _PRIVILEGE_SET
{
    ULONG PrivilegeCount;
    ULONG Control;
    LUID_AND_ATTRIBUTES Privilege[1];
} PRIVILEGE_SET;

typedef struct _KUSER_SHARED_DATA
{
    ULONG TickCountLowDeprecated;
    ULONG TickCountMultiplier;
    KSYSTEM_TIME InterruptTime;
    KSYSTEM_TIME SystemTime;
    KSYSTEM_TIME TimeZoneBias;
    USHORT ImageNumberLow;
    USHORT ImageNumberHigh;
    WCHAR NtSystemRoot[260];
    ULONG MaxStackTraceDepth;
    ULONG CryptoExponent;
    ULONG TimeZoneId;
    ULONG LargePageMinimum;
    ULONG Reserved2[7];
    NT_PRODUCT_TYPE NtProductType;
    UCHAR ProductTypeIsValid;
    ULONG NtMajorVersion;
    ULONG NtMinorVersion;
    UCHAR ProcessorFeatures[64];
    ULONG Reserved1;
    ULONG Reserved3;
    volatile unsigned long TimeSlip;
    ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;
    ULONG AltArchitecturePad[1];
    LARGE_INTEGER SystemExpirationDate;
    ULONG SuiteMask;
    UCHAR KdDebuggerEnabled;
    UCHAR NXSupportPolicy;
    volatile unsigned long ActiveConsoleId;
    volatile unsigned long DismountCount;
    ULONG ComPlusPackage;
    ULONG LastSystemRITEventTickCount;
    ULONG NumberOfPhysicalPages;
    UCHAR SafeBootMode;
    union
    {
        UCHAR TscQpcData;
        struct
        {
            UCHAR TscQpcEnabled : 1;
            UCHAR TscQpcSpareFlag : 1;
            UCHAR TscQpcShift : 6;
        };
    };
    UCHAR TscQpcPad[2];
    union
    {
        ULONG SharedDataFlags;
        struct
        {
            ULONG DbgErrorPortPresent : 1;
            ULONG DbgElevationEnabled : 1;
            ULONG DbgVirtEnabled : 1;
            ULONG DbgInstallerDetectEnabled : 1;
            ULONG DbgSystemDllRelocated : 1;
            ULONG DbgDynProcessorEnabled : 1;
            ULONG DbgSEHValidationEnabled : 1;
            ULONG SpareBits : 25;
        };
    };
    ULONG DataFlagsPad[1];
    ULONGLONG TestRetInstruction;
    ULONG SystemCall;
    ULONG SystemCallReturn;
    ULONGLONG SystemCallPad[3];
    union
    {
        KSYSTEM_TIME TickCount;
        volatile unsigned __int64 TickCountQuad;
        ULONG ReservedTickCountOverlay[3];
    };
    ULONG TickCountPad[1];
    ULONG Cookie;
    ULONG CookiePad[1];
    LONGLONG ConsoleSessionForegroundProcessId;
    ULONG Wow64SharedInformation[16];
    USHORT UserModeGlobalLogger[16];
    ULONG ImageFileExecutionOptions;
    ULONG LangGenerationCount;
    ULONGLONG Reserved5;
    volatile unsigned __int64 InterruptTimeBias;
    volatile unsigned __int64 TscQpcBias;
    volatile unsigned long ActiveProcessorCount;
    volatile unsigned short ActiveGroupCount;
    USHORT Reserved4;
    volatile unsigned long AitSamplingValue;
    volatile unsigned long AppCompatFlag;
    ULONGLONG SystemDllNativeRelocation;
    ULONG SystemDllWowRelocation;
    ULONG XStatePad[1];
    XSTATE_CONFIGURATION XState;
} KUSER_SHARED_DATA;

typedef struct _D3DKMDT_MONITOR_SOURCE_MODE
{
    UINT Id;
    D3DKMDT_VIDEO_SIGNAL_INFO VideoSignalInfo;
    D3DKMDT_COLOR_BASIS ColorBasis;
    D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES ColorCoeffDynamicRanges;
    D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
    D3DKMDT_MODE_PREFERENCE Preference;
} D3DKMDT_MONITOR_SOURCE_MODE;

typedef struct _IO_RESOURCE_LIST
{
    USHORT Version;
    USHORT Revision;
    ULONG Count;
    IO_RESOURCE_DESCRIPTOR Descriptors[1];
} IO_RESOURCE_LIST;

typedef struct _KBDFILE KBDFILE, *PKBDFILE;

struct _KBDFILE
{
    HEAD head;
    PKBDFILE pkfNext;
    VOID *hBase;
    KbdLayer *pKbdTbl;
    ULONG Size;
    KbdNlsLayer *pKbdNlsTbl;
    WCHAR awchDllName[32];
};

typedef struct _D3DKMDT_VIDPN_PRESENT_PATH
{
    UINT VidPnSourceId;
    UINT VidPnTargetId;
    D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE ImportanceOrdinal;
    D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION ContentTransformation;
    D3DKMDT_2DREGION VisibleFromActiveTLOffset;
    D3DKMDT_2DREGION VisibleFromActiveBROffset;
    D3DKMDT_COLOR_BASIS VidPnTargetColorBasis;
    D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES VidPnTargetColorCoeffDynamicRanges;
    D3DKMDT_VIDPN_PRESENT_PATH_CONTENT Content;
    D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION CopyProtection;
    D3DKMDT_GAMMA_RAMP GammaRamp;
} D3DKMDT_VIDPN_PRESENT_PATH;

typedef struct _ERESOURCE
{
    LIST_ENTRY SystemResourcesList;
    OWNER_ENTRY *OwnerTable;
    SHORT ActiveCount;
    USHORT Flag;
    PKSEMAPHORE SharedWaiters;
    PKEVENT ExclusiveWaiters;
    OWNER_ENTRY OwnerEntry;
    ULONG ActiveEntries;
    ULONG ContentionCount;
    ULONG NumberOfSharedWaiters;
    ULONG NumberOfExclusiveWaiters;
    VOID *Reserved2;
    union
    {
        VOID *Address;
        ULONGLONG CreatorBackTraceIndex;
    };
    ULONGLONG SpinLock;
} ERESOURCE, *PERESOURCE;

typedef struct _W32PROCESS W32PROCESS, *PW32PROCESS;

struct _W32PROCESS
{
    EPROCESS *Process;
    ULONG RefCount;
    ULONG W32PF_Flags;
    PKEVENT InputIdleEvent;
    ULONG StartCursorHideTime;
    PW32PROCESS NextStart;
    VOID *pDCAttrList;
    VOID *pBrushAttrList;
    ULONG W32Pid;
    LONG GDIHandleCount;
    ULONG GDIHandleCountPeak;
    LONG UserHandleCount;
    ULONG UserHandleCountPeak;
    EX_PUSH_LOCK GDIPushLock;
    RTL_AVL_TABLE GDIEngUserMemAllocTable;
    LIST_ENTRY GDIDcAttrFreeList;
    LIST_ENTRY GDIBrushAttrFreeList;
    LIST_ENTRY GDIW32PIDLockedBitmaps;
    VOID *hSecureGdiSharedHandleTable;
    VOID *DxProcess;
};

typedef struct _ACCESS_STATE
{
    LUID OperationID;
    UCHAR SecurityEvaluated;
    UCHAR GenerateAudit;
    UCHAR GenerateOnClose;
    UCHAR PrivilegesAllocated;
    ULONG Flags;
    ULONG RemainingDesiredAccess;
    ULONG PreviouslyGrantedAccess;
    ULONG OriginalDesiredAccess;
    SECURITY_SUBJECT_CONTEXT SubjectSecurityContext;
    VOID *SecurityDescriptor;
    VOID *AuxData;
    union
    {
        INITIAL_PRIVILEGE_SET InitialPrivilegeSet;
        PRIVILEGE_SET PrivilegeSet;
    } Privileges;
    UCHAR AuditPrivileges;
    UNICODE_STRING ObjectName;
    UNICODE_STRING ObjectTypeName;
} ACCESS_STATE;

typedef struct _KPROCESSOR_STATE
{
    KSPECIAL_REGISTERS SpecialRegisters;
    CONTEXT ContextFrame;
} KPROCESSOR_STATE;

typedef struct _PEB
{
    UCHAR InheritedAddressSpace;
    UCHAR ReadImageFileExecOptions;
    UCHAR BeingDebugged;
    union
    {
        UCHAR BitField;
        struct
        {
            UCHAR ImageUsesLargePages : 1;
            UCHAR IsProtectedProcess : 1;
            UCHAR IsLegacyProcess : 1;
            UCHAR IsImageDynamicallyRelocated : 1;
            UCHAR SkipPatchingUser32Forwarders : 1;
            UCHAR SpareBits : 3;
        };
    };
    VOID *Mutant;
    VOID *ImageBaseAddress;
    PEB_LDR_DATA *Ldr;
    RTL_USER_PROCESS_PARAMETERS *ProcessParameters;
    VOID *SubSystemData;
    VOID *ProcessHeap;
    RTL_CRITICAL_SECTION *FastPebLock;
    VOID *AtlThunkSListPtr;
    VOID *IFEOKey;
    union
    {
        ULONG CrossProcessFlags;
        struct
        {
            ULONG ProcessInJob : 1;
            ULONG ProcessInitializing : 1;
            ULONG ProcessUsingVEH : 1;
            ULONG ProcessUsingVCH : 1;
            ULONG ProcessUsingFTH : 1;
            ULONG ReservedBits0 : 27;
        };
    };
    union
    {
        VOID *KernelCallbackTable;
        VOID *UserSharedInfoPtr;
    };
    ULONG SystemReserved[1];
    ULONG AtlThunkSListPtr32;
    VOID *ApiSetMap;
    ULONG TlsExpansionCounter;
    VOID *TlsBitmap;
    ULONG TlsBitmapBits[2];
    VOID *ReadOnlySharedMemoryBase;
    VOID *HotpatchInformation;
    VOID **ReadOnlyStaticServerData;
    VOID *AnsiCodePageData;
    VOID *OemCodePageData;
    VOID *UnicodeCaseTableData;
    ULONG NumberOfProcessors;
    ULONG NtGlobalFlag;
    LARGE_INTEGER CriticalSectionTimeout;
    ULONGLONG HeapSegmentReserve;
    ULONGLONG HeapSegmentCommit;
    ULONGLONG HeapDeCommitTotalFreeThreshold;
    ULONGLONG HeapDeCommitFreeBlockThreshold;
    ULONG NumberOfHeaps;
    ULONG MaximumNumberOfHeaps;
    VOID **ProcessHeaps;
    VOID *GdiSharedHandleTable;
    VOID *ProcessStarterHelper;
    ULONG GdiDCAttributeList;
    RTL_CRITICAL_SECTION *LoaderLock;
    ULONG OSMajorVersion;
    ULONG OSMinorVersion;
    USHORT OSBuildNumber;
    USHORT OSCSDVersion;
    ULONG OSPlatformId;
    ULONG ImageSubsystem;
    ULONG ImageSubsystemMajorVersion;
    ULONG ImageSubsystemMinorVersion;
    ULONGLONG ActiveProcessAffinityMask;
    ULONG GdiHandleBuffer[60];
    VOID (*PostProcessInitRoutine)(VOID);
    VOID *TlsExpansionBitmap;
    ULONG TlsExpansionBitmapBits[32];
    ULONG SessionId;
    ULARGE_INTEGER AppCompatFlags;
    ULARGE_INTEGER AppCompatFlagsUser;
    VOID *pShimData;
    VOID *AppCompatInfo;
    UNICODE_STRING CSDVersion;
    ACTIVATION_CONTEXT_DATA *ActivationContextData;
    ASSEMBLY_STORAGE_MAP *ProcessAssemblyStorageMap;
    ACTIVATION_CONTEXT_DATA *SystemDefaultActivationContextData;
    ASSEMBLY_STORAGE_MAP *SystemAssemblyStorageMap;
    ULONGLONG MinimumStackCommit;
    FLS_CALLBACK_INFO *FlsCallback;
    LIST_ENTRY FlsListHead;
    VOID *FlsBitmap;
    ULONG FlsBitmapBits[4];
    ULONG FlsHighIndex;
    VOID *WerRegistrationData;
    VOID *WerShipAssertPtr;
    VOID *pContextData;
    VOID *pImageHeaderHash;
    union
    {
        ULONG TracingFlags;
        struct
        {
            ULONG HeapTracingEnabled : 1;
            ULONG CritSecTracingEnabled : 1;
            ULONG SpareTracingBits : 30;
        };
    };
} PEB, *PPEB;

typedef struct _PAGED_LOOKASIDE_LIST
{
    GENERAL_LOOKASIDE L;
} PAGED_LOOKASIDE_LIST;

typedef struct _DMM_MONITOR_SOURCE_MODE_SERIALIZATION
{
    D3DKMDT_MONITOR_SOURCE_MODE Info;
    D3DKMDT_MONITOR_TIMING_TYPE TimingType;
} DMM_MONITOR_SOURCE_MODE_SERIALIZATION;

typedef struct _DMM_VIDPNTARGETMODESET_SERIALIZATION
{
    UCHAR NumModes;
    D3DKMDT_VIDPN_TARGET_MODE ModeSerialization[1];
} DMM_VIDPNTARGETMODESET_SERIALIZATION;

typedef struct _FAST_MUTEX
{
    volatile long Count;
    KTHREAD *Owner;
    ULONG Contention;
    KEVENT Event;
    ULONG OldIrql;
} FAST_MUTEX;

typedef struct _NPAGED_LOOKASIDE_LIST
{
    GENERAL_LOOKASIDE L;
} NPAGED_LOOKASIDE_LIST;

typedef struct _CM_FULL_RESOURCE_DESCRIPTOR
{
    INTERFACE_TYPE InterfaceType;
    ULONG BusNumber;
    CM_PARTIAL_RESOURCE_LIST PartialResourceList;
} CM_FULL_RESOURCE_DESCRIPTOR;

typedef struct _AUX_ACCESS_DATA
{
    PRIVILEGE_SET *PrivilegesUsed;
    GENERIC_MAPPING GenericMapping;
    ULONG AccessesToAudit;
    ULONG MaximumAuditMask;
    GUID TransactionId;
    VOID *NewSecurityDescriptor;
    VOID *ExistingSecurityDescriptor;
    VOID *ParentSecurityDescriptor;
    VOID (*DeRefSecurityDescriptor)(VOID *, VOID *);
    VOID *SDLock;
    ACCESS_REASONS AccessReasons;
} AUX_ACCESS_DATA;

typedef struct _DMM_MONITORFREQUENCYRANGESET_SERIALIZATION
{
    UCHAR NumFrequencyRanges;
    D3DKMDT_MONITOR_FREQUENCY_RANGE FrequencyRangeSerialization[1];
} DMM_MONITORFREQUENCYRANGESET_SERIALIZATION;

typedef struct _WOWTHREADINFO WOWTHREADINFO, *PWOWTHREADINFO;

struct _WOWTHREADINFO
{
    PWOWTHREADINFO pwtiNext;
    ULONG idTask;
    ULONGLONG idWaitObject;
    ULONG idParentProcess;
    PKEVENT pIdleEvent;
    INT fAssigned;
};

typedef struct _EXCEPTION_REGISTRATION_RECORD EXCEPTION_REGISTRATION_RECORD;

struct _EXCEPTION_REGISTRATION_RECORD
{
    EXCEPTION_REGISTRATION_RECORD *Next;
    EXCEPTION_DISPOSITION (*Handler)(EXCEPTION_RECORD *, VOID *, PCONTEXT, VOID *);
};

typedef struct _WHEA_ERROR_RECORD
{
    WHEA_ERROR_RECORD_HEADER Header;
    WHEA_ERROR_RECORD_SECTION_DESCRIPTOR SectionDescriptor[1];
} WHEA_ERROR_RECORD;

typedef struct _IO_RESOURCE_REQUIREMENTS_LIST
{
    ULONG ListSize;
    INTERFACE_TYPE InterfaceType;
    ULONG BusNumber;
    ULONG SlotNumber;
    ULONG Reserved[3];
    ULONG AlternativeLists;
    IO_RESOURCE_LIST List[1];
} IO_RESOURCE_REQUIREMENTS_LIST;

typedef struct _KL KL, *PKL;

struct _KL
{
    HEAD head;
    PKL pklNext;
    PKL pklPrev;
    ULONG dwKL_Flags;
    HKL__ *hkl;
    PKBDFILE spkf;
    PKBDFILE spkfPrimary;
    ULONG dwFontSigs;
    UINT iBaseCharset;
    USHORT CodePage;
    WCHAR wchDiacritic;
    PIMEINFOEX piiex;
    UINT uNumTbl;
    PKBDFILE *pspkfExtra;
    ULONG dwLastKbdType;
    ULONG dwLastKbdSubType;
    ULONG dwKLID;
};

typedef struct _DMM_VIDPNPATHANDTARGETMODESET_SERIALIZATION
{
    D3DKMDT_VIDPN_PRESENT_PATH PathInfo;
    DMM_VIDPNTARGETMODESET_SERIALIZATION TargetModeSet;
} DMM_VIDPNPATHANDTARGETMODESET_SERIALIZATION;

typedef struct _KPRCB
{
    ULONG MxCsr;
    UCHAR LegacyNumber;
    UCHAR ReservedMustBeZero;
    UCHAR InterruptRequest;
    UCHAR IdleHalt;
    KTHREAD *CurrentThread;
    KTHREAD *NextThread;
    KTHREAD *IdleThread;
    UCHAR NestingLevel;
    UCHAR PrcbPad00[3];
    ULONG Number;
    ULONGLONG RspBase;
    ULONGLONG PrcbLock;
    ULONGLONG PrcbPad01;
    KPROCESSOR_STATE ProcessorState;
    CHAR CpuType;
    CHAR CpuID;
    union
    {
        USHORT CpuStep;
        struct
        {
            UCHAR CpuStepping;
            UCHAR CpuModel;
        };
    };
    ULONG MHz;
    ULONGLONG HalReserved[8];
    USHORT MinorVersion;
    USHORT MajorVersion;
    UCHAR BuildType;
    UCHAR CpuVendor;
    UCHAR CoresPerPhysicalProcessor;
    UCHAR LogicalProcessorsPerCore;
    ULONG ApicMask;
    ULONG CFlushSize;
    VOID *AcpiReserved;
    ULONG InitialApicId;
    ULONG Stride;
    USHORT Group;
    ULONGLONG GroupSetMember;
    UCHAR GroupIndex;
} KPRCB, *PKPRCB;

typedef struct _CM_RESOURCE_LIST
{
    ULONG Count;
    CM_FULL_RESOURCE_DESCRIPTOR List[1];
} CM_RESOURCE_LIST;

typedef struct _OBJECT_TYPE_INITIALIZER
{
    USHORT Length;
    union
    {
        UCHAR ObjectTypeFlags;
        struct
        {
            UCHAR CaseInsensitive : 1;
            UCHAR UnnamedObjectsOnly : 1;
            UCHAR UseDefaultObject : 1;
            UCHAR SecurityRequired : 1;
            UCHAR MaintainHandleCount : 1;
            UCHAR MaintainTypeList : 1;
            UCHAR SupportsObjectCallbacks : 1;
        };
    };
    ULONG ObjectTypeCode;
    ULONG InvalidAttributes;
    GENERIC_MAPPING GenericMapping;
    ULONG ValidAccessMask;
    ULONG RetainAccess;
    POOL_TYPE PoolType;
    ULONG DefaultPagedPoolCharge;
    ULONG DefaultNonPagedPoolCharge;
    VOID (*DumpProcedure)(VOID *, OBJECT_DUMP_CONTROL *);
    LONG (*OpenProcedure)(OB_OPEN_REASON, CHAR, EPROCESS *, VOID *, ULONG *, ULONG);
    VOID (*CloseProcedure)(EPROCESS *, VOID *, ULONGLONG, ULONGLONG);
    VOID (*DeleteProcedure)(VOID *);
    LONG (*ParseProcedure)(VOID *, VOID *, ACCESS_STATE *, CHAR, ULONG, UNICODE_STRING *, UNICODE_STRING *, VOID *, SECURITY_QUALITY_OF_SERVICE *, VOID **);
    LONG (*SecurityProcedure)(VOID *, SECURITY_OPERATION_CODE, ULONG *, VOID *, ULONG *, VOID **, POOL_TYPE, GENERIC_MAPPING *, CHAR);
    LONG (*QueryNameProcedure)(VOID *, UCHAR, OBJECT_NAME_INFORMATION *, ULONG, ULONG *, CHAR);
    UCHAR (*OkayToCloseProcedure)(EPROCESS *, VOID *, VOID *, CHAR);
} OBJECT_TYPE_INITIALIZER;

typedef struct _IO_SECURITY_CONTEXT
{
    SECURITY_QUALITY_OF_SERVICE *SecurityQos;
    ACCESS_STATE *AccessState;
    ULONG DesiredAccess;
    ULONG FullCreateOptions;
} IO_SECURITY_CONTEXT;

typedef struct _DMM_MONITORSOURCEMODESET_SERIALIZATION
{
    UCHAR NumModes;
    DMM_MONITOR_SOURCE_MODE_SERIALIZATION ModeSerialization[1];
} DMM_MONITORSOURCEMODESET_SERIALIZATION;

typedef struct _NT_TIB NT_TIB;

struct _NT_TIB
{
    EXCEPTION_REGISTRATION_RECORD *ExceptionList;
    VOID *StackBase;
    VOID *StackLimit;
    VOID *SubSystemTib;
    union
    {
        VOID *FiberData;
        ULONG Version;
    };
    VOID *ArbitraryUserPointer;
    NT_TIB *Self;
};

typedef struct _DMM_VIDPNPATHANDTARGETMODE_SERIALIZATION
{
    D3DKMDT_VIDPN_PRESENT_PATH PathInfo;
    D3DKMDT_VIDPN_TARGET_MODE TargetMode;
} DMM_VIDPNPATHANDTARGETMODE_SERIALIZATION;

typedef struct _IO_STACK_LOCATION IO_STACK_LOCATION;
typedef struct _DEVOBJ_EXTENSION DEVOBJ_EXTENSION;
typedef struct _IRP IRP, *PIRP;
typedef struct _FILE_OBJECT FILE_OBJECT;
typedef struct _DRIVER_EXTENSION DRIVER_EXTENSION;
typedef struct _FAST_IO_DISPATCH FAST_IO_DISPATCH;
typedef struct _DRIVER_OBJECT DRIVER_OBJECT;
typedef struct _VPB VPB, *PVPB;
typedef struct _WAIT_CONTEXT_BLOCK WAIT_CONTEXT_BLOCK;
typedef struct _DEVICE_OBJECT DEVICE_OBJECT;

struct _IO_STACK_LOCATION
{
    UCHAR MajorFunction;
    UCHAR MinorFunction;
    UCHAR Flags;
    UCHAR Control;
    union
    {
        struct
        {
            IO_SECURITY_CONTEXT *SecurityContext;
            ULONG Options;
            USHORT FileAttributes;
            USHORT ShareAccess;
            ULONG EaLength;
        } Create;
        struct
        {
            IO_SECURITY_CONTEXT *SecurityContext;
            ULONG Options;
            USHORT Reserved;
            USHORT ShareAccess;
            NAMED_PIPE_CREATE_PARAMETERS *Parameters;
        } CreatePipe;
        struct
        {
            IO_SECURITY_CONTEXT *SecurityContext;
            ULONG Options;
            USHORT Reserved;
            USHORT ShareAccess;
            MAILSLOT_CREATE_PARAMETERS *Parameters;
        } CreateMailslot;
        struct
        {
            ULONG Length;
            ULONG Key;
            LARGE_INTEGER ByteOffset;
        } Read;
        struct
        {
            ULONG Length;
            ULONG Key;
            LARGE_INTEGER ByteOffset;
        } Write;
        struct
        {
            ULONG Length;
            UNICODE_STRING *FileName;
            FILE_INFORMATION_CLASS FileInformationClass;
            ULONG FileIndex;
        } QueryDirectory;
        struct
        {
            ULONG Length;
            ULONG CompletionFilter;
        } NotifyDirectory;
        struct
        {
            ULONG Length;
            FILE_INFORMATION_CLASS FileInformationClass;
        } QueryFile;
        struct
        {
            ULONG Length;
            FILE_INFORMATION_CLASS FileInformationClass;
            FILE_OBJECT *FileObject;
            union
            {
                struct
                {
                    UCHAR ReplaceIfExists;
                    UCHAR AdvanceOnly;
                };
                ULONG ClusterCount;
                VOID *DeleteHandle;
            };
        } SetFile;
        struct
        {
            ULONG Length;
            FSINFOCLASS FsInformationClass;
        } QueryVolume;
        struct
        {
            ULONG OutputBufferLength;
            ULONG InputBufferLength;
            ULONG FsControlCode;
            VOID *Type3InputBuffer;
        } FileSystemControl;
        struct
        {
            LARGE_INTEGER *Length;
            ULONG Key;
            LARGE_INTEGER ByteOffset;
        } LockControl;
        struct
        {
            ULONG OutputBufferLength;
            ULONG InputBufferLength;
            ULONG IoControlCode;
            VOID *Type3InputBuffer;
        } DeviceIoControl;
        struct
        {
            ULONG SecurityInformation;
            ULONG Length;
        } QuerySecurity;
        struct
        {
            ULONG SecurityInformation;
            VOID *SecurityDescriptor;
        } SetSecurity;
        struct
        {
            PVPB Vpb;
            DEVICE_OBJECT *DeviceObject;
        } MountVolume;
        struct
        {
            PVPB Vpb;
            DEVICE_OBJECT *DeviceObject;
        } VerifyVolume;
        struct
        {
            SCSI_REQUEST_BLOCK *Srb;
        } Scsi;
        struct
        {
            DEVICE_RELATION_TYPE Type;
        } QueryDeviceRelations;
        struct
        {
            PGUID InterfaceType;
            USHORT Size;
            USHORT Version;
            PINTERFACE Interface;
            VOID *InterfaceSpecificData;
        } QueryInterface;
        struct
        {
            DEVICE_CAPABILITIES *Capabilities;
        } DeviceCapabilities;
        struct
        {
            IO_RESOURCE_REQUIREMENTS_LIST *IoResourceRequirementList;
        } FilterResourceRequirements;
        struct
        {
            ULONG WhichSpace;
            VOID *Buffer;
            ULONG Offset;
            ULONG Length;
        } ReadWriteConfig;
        struct
        {
            UCHAR Lock;
        } SetLock;
        struct
        {
            BUS_QUERY_ID_TYPE IdType;
        } QueryId;
        struct
        {
            DEVICE_TEXT_TYPE DeviceTextType;
            ULONG LocaleId;
        } QueryDeviceText;
        struct
        {
            UCHAR InPath;
            UCHAR Reserved[3];
            DEVICE_USAGE_NOTIFICATION_TYPE Type;
        } UsageNotification;
        struct
        {
            SYSTEM_POWER_STATE PowerState;
        } WaitWake;
        struct
        {
            POWER_SEQUENCE *PowerSequence;
        } PowerSequence;
        struct
        {
            union
            {
                ULONG SystemContext;
                SYSTEM_POWER_STATE_CONTEXT SystemPowerStateContext;
            };
            POWER_STATE_TYPE Type;
            POWER_STATE State;
            POWER_ACTION ShutdownType;
        } Power;
        struct
        {
            CM_RESOURCE_LIST *AllocatedResources;
            CM_RESOURCE_LIST *AllocatedResourcesTranslated;
        } StartDevice;
        struct
        {
            ULONGLONG ProviderId;
            VOID *DataPath;
            ULONG BufferSize;
            VOID *Buffer;
        } WMI;
        struct
        {
            VOID *Argument1;
            VOID *Argument2;
            VOID *Argument3;
            VOID *Argument4;
        } Others;
    } Parameters;
    DEVICE_OBJECT *DeviceObject;
    FILE_OBJECT *FileObject;
    LONG (*CompletionRoutine)(DEVICE_OBJECT *, PIRP, VOID *);
    VOID *Context;
};
struct _DEVOBJ_EXTENSION
{
    SHORT Type;
    USHORT Size;
    DEVICE_OBJECT *DeviceObject;
    ULONG PowerFlags;
    DEVICE_OBJECT_POWER_EXTENSION *Dope;
    ULONG ExtensionFlags;
    VOID *DeviceNode;
    DEVICE_OBJECT *AttachedTo;
    LONG StartIoCount;
    LONG StartIoKey;
    ULONG StartIoFlags;
    PVPB Vpb;
    LIST_ENTRY DependentList;
    LIST_ENTRY ProviderList;
};
struct _IRP
{
    SHORT Type;
    USHORT Size;
    PMDL MdlAddress;
    ULONG Flags;
    union
    {
        PIRP MasterIrp;
        LONG IrpCount;
        VOID *SystemBuffer;
    } AssociatedIrp;
    LIST_ENTRY ThreadListEntry;
    IO_STATUS_BLOCK IoStatus;
    CHAR RequestorMode;
    UCHAR PendingReturned;
    CHAR StackCount;
    CHAR CurrentLocation;
    UCHAR Cancel;
    UCHAR CancelIrql;
    CHAR ApcEnvironment;
    UCHAR AllocationFlags;
    IO_STATUS_BLOCK *UserIosb;
    PKEVENT UserEvent;
    union
    {
        struct
        {
            union
            {
                VOID (*UserApcRoutine)(VOID *, IO_STATUS_BLOCK *, ULONG);
                VOID *IssuingProcess;
            };
            VOID *UserApcContext;
        } AsynchronousParameters;
        LARGE_INTEGER AllocationSize;
    } Overlay;
    VOID (*CancelRoutine)(DEVICE_OBJECT *, PIRP);
    VOID *UserBuffer;
    union
    {
        struct
        {
            union
            {
                KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
                VOID *DriverContext[4];
            };
            ETHREAD *Thread;
            CHAR *AuxiliaryBuffer;
            LIST_ENTRY ListEntry;
            union
            {
                IO_STACK_LOCATION *CurrentStackLocation;
                ULONG PacketType;
            };
            FILE_OBJECT *OriginalFileObject;
        } Overlay;
        KAPC Apc;
        VOID *CompletionKey;
    } Tail;
};
struct _FILE_OBJECT
{
    SHORT Type;
    SHORT Size;
    DEVICE_OBJECT *DeviceObject;
    PVPB Vpb;
    VOID *FsContext;
    VOID *FsContext2;
    SECTION_OBJECT_POINTERS *SectionObjectPointer;
    VOID *PrivateCacheMap;
    LONG FinalStatus;
    FILE_OBJECT *RelatedFileObject;
    UCHAR LockOperation;
    UCHAR DeletePending;
    UCHAR ReadAccess;
    UCHAR WriteAccess;
    UCHAR DeleteAccess;
    UCHAR SharedRead;
    UCHAR SharedWrite;
    UCHAR SharedDelete;
    ULONG Flags;
    UNICODE_STRING FileName;
    LARGE_INTEGER CurrentByteOffset;
    ULONG Waiters;
    ULONG Busy;
    VOID *LastLock;
    KEVENT Lock;
    KEVENT Event;
    IO_COMPLETION_CONTEXT *CompletionContext;
    ULONGLONG IrpListLock;
    LIST_ENTRY IrpList;
    VOID *FileObjectExtension;
};
struct _DRIVER_EXTENSION
{
    DRIVER_OBJECT *DriverObject;
    LONG (*AddDevice)(DRIVER_OBJECT *, DEVICE_OBJECT *);
    ULONG Count;
    UNICODE_STRING ServiceKeyName;
};
struct _FAST_IO_DISPATCH
{
    ULONG SizeOfFastIoDispatch;
    UCHAR (*FastIoCheckIfPossible)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, UCHAR, ULONG, UCHAR, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoRead)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, UCHAR, ULONG, VOID *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoWrite)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, UCHAR, ULONG, VOID *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoQueryBasicInfo)(FILE_OBJECT *, UCHAR, FILE_BASIC_INFORMATION *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoQueryStandardInfo)(FILE_OBJECT *, UCHAR, FILE_STANDARD_INFORMATION *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoLock)(FILE_OBJECT *, LARGE_INTEGER *, LARGE_INTEGER *, EPROCESS *, ULONG, UCHAR, UCHAR, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoUnlockSingle)(FILE_OBJECT *, LARGE_INTEGER *, LARGE_INTEGER *, EPROCESS *, ULONG, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoUnlockAll)(FILE_OBJECT *, EPROCESS *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoUnlockAllByKey)(FILE_OBJECT *, VOID *, ULONG, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*FastIoDeviceControl)(FILE_OBJECT *, UCHAR, VOID *, ULONG, VOID *, ULONG, ULONG, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    VOID (*AcquireFileForNtCreateSection)(FILE_OBJECT *);
    VOID (*ReleaseFileForNtCreateSection)(FILE_OBJECT *);
    VOID (*FastIoDetachDevice)(DEVICE_OBJECT *, DEVICE_OBJECT *);
    UCHAR (*FastIoQueryNetworkOpenInfo)(FILE_OBJECT *, UCHAR, FILE_NETWORK_OPEN_INFORMATION *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    LONG (*AcquireForModWrite)(FILE_OBJECT *, LARGE_INTEGER *, PERESOURCE *, DEVICE_OBJECT *);
    UCHAR (*MdlRead)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, ULONG, PMDL *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*MdlReadComplete)(FILE_OBJECT *, PMDL, DEVICE_OBJECT *);
    UCHAR (*PrepareMdlWrite)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, ULONG, PMDL *, IO_STATUS_BLOCK *, DEVICE_OBJECT *);
    UCHAR (*MdlWriteComplete)(FILE_OBJECT *, LARGE_INTEGER *, PMDL, DEVICE_OBJECT *);
    UCHAR (*FastIoReadCompressed)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, ULONG, VOID *, PMDL *, IO_STATUS_BLOCK *, COMPRESSED_DATA_INFO *, ULONG, DEVICE_OBJECT *);
    UCHAR (*FastIoWriteCompressed)(FILE_OBJECT *, LARGE_INTEGER *, ULONG, ULONG, VOID *, PMDL *, IO_STATUS_BLOCK *, COMPRESSED_DATA_INFO *, ULONG, DEVICE_OBJECT *);
    UCHAR (*MdlReadCompleteCompressed)(FILE_OBJECT *, PMDL, DEVICE_OBJECT *);
    UCHAR (*MdlWriteCompleteCompressed)(FILE_OBJECT *, LARGE_INTEGER *, PMDL, DEVICE_OBJECT *);
    UCHAR (*FastIoQueryOpen)(PIRP, FILE_NETWORK_OPEN_INFORMATION *, DEVICE_OBJECT *);
    LONG (*ReleaseForModWrite)(FILE_OBJECT *, PERESOURCE, DEVICE_OBJECT *);
    LONG (*AcquireForCcFlush)(FILE_OBJECT *, DEVICE_OBJECT *);
    LONG (*ReleaseForCcFlush)(FILE_OBJECT *, DEVICE_OBJECT *);
};
struct _DRIVER_OBJECT
{
    SHORT Type;
    SHORT Size;
    DEVICE_OBJECT *DeviceObject;
    ULONG Flags;
    VOID *DriverStart;
    ULONG DriverSize;
    VOID *DriverSection;
    DRIVER_EXTENSION *DriverExtension;
    UNICODE_STRING DriverName;
    UNICODE_STRING *HardwareDatabase;
    FAST_IO_DISPATCH *FastIoDispatch;
    LONG (*DriverInit)(DRIVER_OBJECT *, UNICODE_STRING *);
    VOID (*DriverStartIo)(DEVICE_OBJECT *, PIRP);
    VOID (*DriverUnload)(DRIVER_OBJECT *);
    LONG (*MajorFunction[28])(DEVICE_OBJECT *, PIRP);
};
struct _VPB
{
    SHORT Type;
    SHORT Size;
    USHORT Flags;
    USHORT VolumeLabelLength;
    DEVICE_OBJECT *DeviceObject;
    DEVICE_OBJECT *RealDevice;
    ULONG SerialNumber;
    ULONG ReferenceCount;
    WCHAR VolumeLabel[32];
};
struct _WAIT_CONTEXT_BLOCK
{
    KDEVICE_QUEUE_ENTRY WaitQueueEntry;
    IO_ALLOCATION_ACTION (*DeviceRoutine)(DEVICE_OBJECT *, PIRP, VOID *, VOID *);
    VOID *DeviceContext;
    ULONG NumberOfMapRegisters;
    VOID *DeviceObject;
    VOID *CurrentIrp;
    PKDPC BufferChainingDpc;
};
struct _DEVICE_OBJECT
{
    SHORT Type;
    USHORT Size;
    LONG ReferenceCount;
    DRIVER_OBJECT *DriverObject;
    DEVICE_OBJECT *NextDevice;
    DEVICE_OBJECT *AttachedDevice;
    PIRP CurrentIrp;
    IO_TIMER *Timer;
    ULONG Flags;
    ULONG Characteristics;
    PVPB Vpb;
    VOID *DeviceExtension;
    ULONG DeviceType;
    CHAR StackSize;
    union
    {
        LIST_ENTRY ListEntry;
        WAIT_CONTEXT_BLOCK Wcb;
    } Queue;
    ULONG AlignmentRequirement;
    KDEVICE_QUEUE DeviceQueue;
    KDPC Dpc;
    ULONG ActiveThreadCount;
    VOID *SecurityDescriptor;
    KEVENT DeviceLock;
    USHORT SectorSize;
    USHORT Spare1;
    DEVOBJ_EXTENSION *DeviceObjectExtension;
    VOID *Reserved;
};

typedef struct _CARET CARET, *PCARET;
typedef struct _DISPLAYINFO DISPLAYINFO, *PDISPLAYINFO;
typedef struct _PROCESSINFO PROCESSINFO, *PPROCESSINFO;
typedef struct _SMS SMS, *PSMS;
typedef struct _DESKTOP DESKTOP, *PDESKTOP;
typedef struct _DESKTOPVIEW DESKTOPVIEW, *PDESKTOPVIEW;
typedef struct _PROCESS_HID_REQUEST PROCESS_HID_REQUEST;
typedef struct _W32JOB W32JOB, *PW32JOB;
typedef struct _DCE DCE, *PDCE;
typedef struct _VWPLELEMENT VWPLELEMENT, *PVWPLELEMENT;
typedef struct _POPUPMENU POPUPMENU, *PPOPUPMENU;
typedef struct _SBTRACK SBTRACK, *PSBTRACK;
typedef struct _MLIST MLIST, *PMLIST;
typedef struct _MENUSTATE MENUSTATE, *PMENUSTATE;
typedef struct _THRDESKHEAD THRDESKHEAD, *PTHRDESKHEAD;
typedef struct _SPB SPB, *PSPB;
typedef struct _WINDOWSTATION WINDOWSTATION, *PWINDOWSTATION;
typedef struct _THROBJHEAD THROBJHEAD, *PTHROBJHEAD;
typedef struct _MAGNIFICATION_INPUT_TRANSFORM MAGNIFICATION_INPUT_TRANSFORM;
typedef struct _DESKTOPINFO DESKTOPINFO, *PDESKTOPINFO;
typedef struct _MENULIST MENULIST, *PMENULIST;
typedef struct _CLS CLS, *PCLS;
typedef struct _CALLBACKWND CALLBACKWND, *PCALLBACKWND;
typedef struct _ITEM ITEM, *PITEM;
typedef struct _MOVESIZEDATA MOVESIZEDATA, *PMOVESIZEDATA;
typedef struct _PROCDESKHEAD PROCDESKHEAD, *PPROCDESKHEAD;
typedef struct _TERMINAL TERMINAL, *PTERMINAL;
typedef struct _PROCMARKHEAD PROCMARKHEAD, *PPROCMARKHEAD;
typedef struct _PROCESS_HID_TABLE PROCESS_HID_TABLE;
typedef struct _TDB TDB, *PTDB;
typedef struct _QMSG QMSG, *PQMSG;
typedef struct _WOWPROCESSINFO WOWPROCESSINFO, *PWOWPROCESSINFO;
typedef struct _CURSOR CURSOR, *PCURSOR;
typedef struct _IMC IMC, *PIMC;
typedef struct _CLIENTINFO CLIENTINFO, *PCLIENTINFO;
typedef struct _VWPL VWPL, *PVWPL;
typedef struct _WND WND, *PWND;
typedef struct _SVR_INSTANCE_INFO SVR_INSTANCE_INFO;
typedef struct _MENU MENU, *PMENU;
typedef struct _CALLPROCDATA CALLPROCDATA, *PCALLPROCDATA;
typedef struct _THREADINFO THREADINFO, *PTHREADINFO;
typedef struct _Q Q, *PQ;
typedef struct _HOOK HOOK, *PHOOK;

struct _CARET
{
    PWND spwnd;
    UINT fVisible : 1;
    UINT fOn : 1;
    INT iHideLevel;
    INT x;
    INT y;
    INT cy;
    INT cx;
    HBITMAP__ *hBitmap;
    ULONGLONG hTimer;
    ULONG tid;
    INT xOwnDc;
    INT yOwnDc;
    INT cxOwnDc;
    INT cyOwnDc;
};
struct _DISPLAYINFO
{
    VOID *hDev;
    VOID *pmdev;
    VOID *hDevInfo;
    HDC__ *hdcScreen;
    HDC__ *hdcBits;
    HDC__ *hdcGray;
    HBITMAP__ *hbmGray;
    INT cxGray;
    INT cyGray;
    PDCE pdceFirst;
    PSPB pspbFirst;
    ULONG cMonitors;
    PMONITOR pMonitorPrimary;
    PMONITOR pMonitorFirst;
    RECT rcScreenReal;
    HRGN__ *hrgnScreenReal;
    USHORT dmLogPixels;
    USHORT BitCountMax;
    INT fDesktopIsRect : 1;
    INT fAnyPalette : 1;
    ULONG DockThresholdMax;
    KLIST_ENTRY SpatialListHead;
    SHORT cFullScreen;
    SHORT Spare0;
};
struct _PROCESSINFO
{
    EPROCESS *Process;
    ULONG RefCount;
    ULONG W32PF_Flags;
    PKEVENT InputIdleEvent;
    ULONG StartCursorHideTime;
    PW32PROCESS NextStart;
    VOID *pDCAttrList;
    VOID *pBrushAttrList;
    ULONG W32Pid;
    LONG GDIHandleCount;
    ULONG GDIHandleCountPeak;
    LONG UserHandleCount;
    ULONG UserHandleCountPeak;
    EX_PUSH_LOCK GDIPushLock;
    RTL_AVL_TABLE GDIEngUserMemAllocTable;
    LIST_ENTRY GDIDcAttrFreeList;
    LIST_ENTRY GDIBrushAttrFreeList;
    LIST_ENTRY GDIW32PIDLockedBitmaps;
    VOID *hSecureGdiSharedHandleTable;
    VOID *DxProcess;
    PTHREADINFO ptiList;
    PTHREADINFO ptiMainThread;
    PDESKTOP rpdeskStartup;
    PCLS pclsPrivateList;
    PCLS pclsPublicList;
    PWOWPROCESSINFO pwpi;
    PPROCESSINFO ppiNext;
    PPROCESSINFO ppiNextRunning;
    UINT cThreads;
    HDESK__ *hdeskStartup;
    UINT cSysExpunge;
    ULONG dwhmodLibLoadedMask;
    VOID *ahmodLibLoaded[32];
    PWINDOWSTATION rpwinsta;
    HWINSTA__ *hwinsta;
    ULONG amwinsta;
    ULONG dwHotkey;
    HMONITOR__ *hMonitor;
    PDESKTOPVIEW pdvList;
    UINT iClipSerialNumber;
    RTL_BITMAP bmHandleFlags;
    PCURSOR pCursorCache;
    VOID *pClientBase;
    ULONG dwLpkEntryPoints;
    PW32JOB pW32Job;
    ULONG dwImeCompatFlags;
    LUID luidSession;
    USERSTARTUPINFO usi;
    union
    {
        ULONG Flags;
        struct
        {
            UINT fHasMagContext : 1;
            UINT Unused : 31;
        };
    };
    ULONG dwLayout;
    PROCESS_HID_TABLE *pHidTable;
    ULONG dwRegisteredClasses;
    PVWPL pvwplWndGCList;
};
struct _SMS
{
    PSMS psmsNext;
    PSMS psmsReceiveNext;
    PTHREADINFO ptiSender;
    PTHREADINFO ptiReceiver;
    VOID (*lpResultCallBack)(HWND__ *, UINT, ULONGLONG, LONGLONG);
    ULONGLONG dwData;
    PTHREADINFO ptiCallBackSender;
    LONGLONG lRet;
    ULONG tSent;
    UINT flags;
    ULONGLONG wParam;
    LONGLONG lParam;
    UINT message;
    PWND spwnd;
    VOID *pvCapture;
};
struct _DESKTOP
{
    ULONG dwSessionId;
    PDESKTOPINFO pDeskInfo;
    PDISPLAYINFO pDispInfo;
    PDESKTOP rpdeskNext;
    PWINDOWSTATION rpwinstaParent;
    ULONG dwDTFlags;
    ULONGLONG dwDesktopId;
    PMENU spmenuSys;
    PMENU spmenuDialogSys;
    PMENU spmenuHScroll;
    PMENU spmenuVScroll;
    PWND spwndForeground;
    PWND spwndTray;
    PWND spwndMessage;
    PWND spwndTooltip;
    VOID *hsectionDesktop;
    WIN32HEAP *pheapDesktop;
    ULONG ulHeapSize;
    CONSOLE_CARET_INFO cciConsole;
    LIST_ENTRY PtiList;
    PWND spwndTrack;
    INT htEx;
    RECT rcMouseHover;
    ULONG dwMouseHoverTime;
    MAGNIFICATION_INPUT_TRANSFORM *pMagInputTransform;
};
struct _DESKTOPVIEW
{
    PDESKTOPVIEW pdvNext;
    PDESKTOP pdesk;
    ULONGLONG ulClientDelta;
};
struct _PROCESS_HID_REQUEST
{
    LIST_ENTRY link;
    USHORT usUsagePage;
    USHORT usUsage;
    INT fSinkable : 1;
    INT fExSinkable : 1;
    INT fDevNotify : 1;
    INT fExclusiveOrphaned : 1;
    union
    {
        HID_TLC_INFO *pTLCInfo;
        HID_PAGEONLY_REQUEST *pPORequest;
        VOID *ptr;
    };
    PWND spwndTarget;
};
struct _W32JOB
{
    PW32JOB pNext;
    EJOB *Job;
    VOID *pAtomTable;
    ULONG restrictions;
    UINT uProcessCount;
    UINT uMaxProcesses;
    PPROCESSINFO *ppiTable;
    UINT ughCrt;
    UINT ughMax;
    ULONGLONG *pgh;
};
struct _DCE
{
    PDCE pdceNext;
    HDC__ *hdc;
    PWND pwndOrg;
    PWND pwndClip;
    PWND pwndRedirect;
    HRGN__ *hrgnClip;
    HRGN__ *hrgnClipPublic;
    HRGN__ *hrgnSavedVis;
    ULONG DCX_flags;
    PTHREADINFO ptiOwner;
    PPROCESSINFO ppiOwner;
    PMONITOR pMonitor;
};
struct _VWPLELEMENT
{
    ULONGLONG DataOrTag;
    PWND pwnd;
};
struct _POPUPMENU
{
    ULONG fIsMenuBar : 1;
    ULONG fHasMenuBar : 1;
    ULONG fIsSysMenu : 1;
    ULONG fIsTrackPopup : 1;
    ULONG fDroppedLeft : 1;
    ULONG fHierarchyDropped : 1;
    ULONG fRightButton : 1;
    ULONG fToggle : 1;
    ULONG fSynchronous : 1;
    ULONG fFirstClick : 1;
    ULONG fDropNextPopup : 1;
    ULONG fNoNotify : 1;
    ULONG fAboutToHide : 1;
    ULONG fShowTimer : 1;
    ULONG fHideTimer : 1;
    ULONG fDestroyed : 1;
    ULONG fDelayedFree : 1;
    ULONG fFlushDelayedFree : 1;
    ULONG fFreed : 1;
    ULONG fInCancel : 1;
    ULONG fTrackMouseEvent : 1;
    ULONG fSendUninit : 1;
    ULONG fRtoL : 1;
    ULONG iDropDir : 5;
    ULONG fUseMonitorRect : 1;
    PWND spwndNotify;
    PWND spwndPopupMenu;
    PWND spwndNextPopup;
    PWND spwndPrevPopup;
    PMENU spmenu;
    PMENU spmenuAlternate;
    PWND spwndActivePopup;
    PPOPUPMENU ppopupmenuRoot;
    PPOPUPMENU ppmDelayedFree;
    UINT posSelectedItem;
    UINT posDropped;
};
struct _SBTRACK
{
    ULONG fHitOld : 1;
    ULONG fTrackVert : 1;
    ULONG fCtlSB : 1;
    ULONG fTrackRecalc : 1;
    PWND spwndTrack;
    PWND spwndSB;
    PWND spwndSBNotify;
    RECT rcTrack;
    VOID (*xxxpfnSB)(PWND, UINT, ULONGLONG, LONGLONG, PSBCALC);
    UINT cmdSB;
    ULONGLONG hTimerSB;
    INT dpxThumb;
    INT pxOld;
    INT posOld;
    INT posNew;
    INT nBar;
    PSBCALC pSBCalc;
};
struct _MLIST
{
    PQMSG pqmsgRead;
    PQMSG pqmsgWriteLast;
    ULONG cMsgs;
};
struct _MENUSTATE
{
    PPOPUPMENU pGlobalPopupMenu;
    ULONG fMenuStarted : 1;
    ULONG fIsSysMenu : 1;
    ULONG fInsideMenuLoop : 1;
    ULONG fButtonDown : 1;
    ULONG fInEndMenu : 1;
    ULONG fUnderline : 1;
    ULONG fButtonAlwaysDown : 1;
    ULONG fDragging : 1;
    ULONG fModelessMenu : 1;
    ULONG fInCallHandleMenuMessages : 1;
    ULONG fDragAndDrop : 1;
    ULONG fAutoDismiss : 1;
    ULONG fAboutToAutoDismiss : 1;
    ULONG fIgnoreButtonUp : 1;
    ULONG fMouseOffMenu : 1;
    ULONG fInDoDragDrop : 1;
    ULONG fActiveNoForeground : 1;
    ULONG fNotifyByPos : 1;
    ULONG fSetCapture : 1;
    ULONG iAniDropDir : 5;
    POINT ptMouseLast;
    INT mnFocus;
    INT cmdLast;
    PTHREADINFO ptiMenuStateOwner;
    ULONG dwLockCount;
    PMENUSTATE pmnsPrev;
    POINT ptButtonDown;
    ULONGLONG uButtonDownHitArea;
    UINT uButtonDownIndex;
    INT vkButtonDown;
    ULONGLONG uDraggingHitArea;
    UINT uDraggingIndex;
    UINT uDraggingFlags;
    HDC__ *hdcWndAni;
    ULONG dwAniStartTime;
    INT ixAni;
    INT iyAni;
    INT cxAni;
    INT cyAni;
    HBITMAP__ *hbmAni;
    HDC__ *hdcAni;
};
struct _THRDESKHEAD
{
    VOID *h;
    ULONG cLockObj;
    PTHREADINFO pti;
    PDESKTOP rpdesk;
    UCHAR *pSelf;
};
struct _SPB
{
    PSPB pspbNext;
    PWND spwnd;
    HBITMAP__ *hbm;
    RECT rc;
    HRGN__ *hrgn;
    ULONG flags;
    ULONGLONG ulSaveId;
};
struct _WINDOWSTATION
{
    ULONG dwSessionId;
    PWINDOWSTATION rpwinstaNext;
    PDESKTOP rpdeskList;
    PTERMINAL pTerm;
    ULONG dwWSF_Flags;
    PKL spklList;
    PTHREADINFO ptiClipLock;
    PTHREADINFO ptiDrawingClipboard;
    PWND spwndClipOpen;
    PWND spwndClipViewer;
    PWND spwndClipOwner;
    PCLIP pClipBase;
    UINT cNumClipFormats;
    UINT iClipSerialNumber;
    UINT iClipSequenceNumber;
    PWND spwndClipboardListener;
    VOID *pGlobalAtomTable;
    LUID luidEndSession;
    LUID luidUser;
    VOID *psidUser;
};
struct _THROBJHEAD
{
    VOID *h;
    ULONG cLockObj;
    PTHREADINFO pti;
};
struct _MAGNIFICATION_INPUT_TRANSFORM
{
    RECT rcSource;
    RECT rcScreen;
    PTHREADINFO ptiMagThreadInfo;
    INT magFactorX;
    INT magFactorY;
};
struct _DESKTOPINFO
{
    VOID *pvDesktopBase;
    VOID *pvDesktopLimit;
    PWND spwnd;
    ULONG fsHooks;
    PHOOK aphkStart[16];
    PWND spwndShell;
    PPROCESSINFO ppiShellProcess;
    PWND spwndBkGnd;
    PWND spwndTaskman;
    PWND spwndProgman;
    PVWPL pvwplShellHook;
    INT cntMBox;
    PWND spwndGestureEngine;
    PVWPL pvwplMessagePPHandler;
    ULONG fComposited : 1;
    ULONG fIsDwmDesktop : 1;
};
struct _MENULIST
{
    PMENULIST pNext;
    PMENU pMenu;
};
struct _CLS
{
    PCLS pclsNext;
    USHORT atomClassName;
    USHORT atomNVClassName;
    USHORT fnid;
    PDESKTOP rpdeskParent;
    PDCE pdce;
    USHORT hTaskWow;
    USHORT CSF_flags;
    CHAR *lpszClientAnsiMenuName;
    USHORT *lpszClientUnicodeMenuName;
    PCALLPROCDATA spcpdFirst;
    PCLS pclsBase;
    PCLS pclsClone;
    INT cWndReferenceCount;
    UINT style;
    LONGLONG (*lpfnWndProc)(PWND, UINT, ULONGLONG, LONGLONG);
    INT cbclsExtra;
    INT cbwndExtra;
    VOID *hModule;
    PCURSOR spicn;
    PCURSOR spcur;
    HBRUSH__ *hbrBackground;
    USHORT *lpszMenuName;
    CHAR *lpszAnsiClassName;
    PCURSOR spicnSm;
};
struct _CALLBACKWND
{
    HWND__ *hwnd;
    PWND pwnd;
    ACTIVATION_CONTEXT *pActCtx;
};
struct _ITEM
{
    UINT fType;
    UINT fState;
    UINT wID;
    PMENU spSubMenu;
    VOID *hbmpChecked;
    VOID *hbmpUnchecked;
    USHORT *lpstr;
    ULONG cch;
    ULONGLONG dwItemData;
    ULONG xItem;
    ULONG yItem;
    ULONG cxItem;
    ULONG cyItem;
    ULONG dxTab;
    ULONG ulX;
    ULONG ulWidth;
    HBITMAP__ *hbmp;
    INT cxBmp;
    INT cyBmp;
    UAHMENUITEMMETRICS umim;
};
struct _MOVESIZEDATA
{
    PWND spwnd;
    RECT rcDrag;
    RECT rcDragCursor;
    RECT rcPreview;
    RECT rcPreviewCursor;
    RECT rcParent;
    POINT ptMinTrack;
    POINT ptMaxTrack;
    RECT rcWindow;
    RECT rcNormalStartCheckPt;
    INT dxMouse;
    INT dyMouse;
    INT cmd;
    INT impx;
    INT impy;
    POINT ptRestore;
    union
    {
        ULONG Flags;
        struct
        {
            UINT fInitSize : 1;
            UINT fmsKbd : 1;
            UINT fLockWindowUpdate : 1;
            UINT fTrackCancelled : 1;
            UINT fForeground : 1;
            UINT fDragFullWindows : 1;
            UINT fOffScreen : 1;
            UINT fMoveFromMax : 1;
            UINT fVerticallyMaximizedLeft : 1;
            UINT fVerticallyMaximizedRight : 1;
            UINT fSnapSizing : 1;
            UINT fSnapMoving : 1;
            UINT fWindowWasSuperMaximized : 1;
            UINT fStartVerticallyMaximizedLeft : 1;
            UINT fStartVerticallyMaximizedRight : 1;
            UINT fThresholdSelector : 3;
            UINT fCheckPtForcefullyRestored : 1;
            UINT fForceSizing : 1;
            UINT fIsMoveSizeLoop : 1;
            UINT fIsHitPtOffScreen : 1;
            UINT fSnapSizingTemporaryAllowed : 1;
            UINT fSnapMovingTemporaryAllowed : 1;
            UINT frcNormalCheckPtValid : 1;
            UINT fHasPreviewRect : 1;
            UINT fUsePreviewRect : 1;
            UINT fHasSoftwareCursor : 1;
            UINT Unused : 4;
        };
    };
    PMONITOR pStartMonitorCurrentHitTarget;
    eTHRESHOLD_MARGIN_DIRECTION StartCurrentHitTarget;
    PMONITOR pMonitorCurrentHitTarget;
    eTHRESHOLD_MARGIN_DIRECTION CurrentHitTarget;
    MOVERECT_STYLE MoveRectStyle;
    POINT ptHitWindowRelative;
    POINT ptStartHitWindowRelative;
    POINT ptLastTrack;
    ULONG ulCountDragOutOfTopTarget;
    ULONG ulCountDragOutOfLeftRightTarget;
    ULONG ulCountSizeOutOfTopBottomTarget;
};
struct _PROCDESKHEAD
{
    VOID *h;
    ULONG cLockObj;
    ULONG hTaskWow;
    PDESKTOP rpdesk;
    UCHAR *pSelf;
};
struct _TERMINAL
{
    ULONG dwTERMF_Flags;
    PWND spwndDesktopOwner;
    PTHREADINFO ptiDesktop;
    PQ pqDesktop;
    ULONG dwNestedLevel;
    PKEVENT pEventTermInit;
    PDESKTOP rpdeskDestroy;
    PKEVENT pEventInputReady;
};
struct _PROCMARKHEAD
{
    VOID *h;
    ULONG cLockObj;
    ULONG hTaskWow;
    PPROCESSINFO ppi;
};
struct _PROCESS_HID_TABLE
{
    LIST_ENTRY link;
    LIST_ENTRY InclusionList;
    LIST_ENTRY UsagePageList;
    LIST_ENTRY ExclusionList;
    PWND spwndTargetMouse;
    PWND spwndTargetKbd;
    INT nSinks;
    PROCESS_HID_REQUEST *pLastRequest;
    USHORT UsagePageLast;
    USHORT UsageLast;
    INT fRawMouse : 1;
    INT fNoLegacyMouse : 1;
    INT fRawMouseSink : 1;
    INT fExclusiveMouseSink : 1;
    INT fRawKeyboard : 1;
    INT fNoLegacyKeyboard : 1;
    INT fRawKeyboardSink : 1;
    INT fExclusiveKeyboardSink : 1;
    INT fCaptureMouse : 1;
    INT fNoHotKeys : 1;
    INT fAppKeys : 1;
};
struct _TDB
{
    PTDB ptdbNext;
    INT nEvents;
    INT nPriority;
    PTHREADINFO pti;
    PWOWTHREADINFO pwti;
    USHORT hTaskWow;
    USHORT TDB_Flags;
};
struct _QMSG
{
    PQMSG pqmsgNext;
    PQMSG pqmsgPrev;
    MSG msg;
    LONGLONG ExtraInfo;
    POINT ptMouseReal;
    ULONG dwQEvent : 30;
    ULONG Padding : 2;
    INT Wow64Message : 1;
    INT NoCoalesce : 1;
    INT FromTouch : 1;
    INT FromPen : 1;
    PTHREADINFO pti;
    MSGPPINFO MsgPPInfo;
};
struct _WOWPROCESSINFO
{
    PWOWPROCESSINFO pwpiNext;
    PTHREADINFO ptiScheduled;
    PTDB ptdbHead;
    VOID *lpfnWowExitTask;
    PKEVENT pEventWowExec;
    VOID *hEventWowExecClient;
    ULONG nSendLock;
    ULONG nRecvLock;
    PTHREADINFO CSOwningThread;
    LONG CSLockCount;
};
struct _CURSOR
{
    PROCMARKHEAD head;
    PCURSOR pcurNext;
    UNICODE_STRING strName;
    USHORT atomModName;
    USHORT rt;
    ULONG CURSORF_flags;
    SHORT xHotspot;
    SHORT yHotspot;
    HBITMAP__ *hbmMask;
    HBITMAP__ *hbmColor;
    HBITMAP__ *hbmAlpha;
    RECT rcBounds;
    HBITMAP__ *hbmUserAlpha;
    ULONG bpp;
    ULONG cx;
    ULONG cy;
};
struct _IMC
{
    THRDESKHEAD head;
    PIMC pImcNext;
    ULONGLONG dwClientImcData;
    HWND__ *hImeWnd;
};
struct _CLIENTINFO
{
    ULONGLONG CI_flags;
    ULONGLONG cSpins;
    ULONG dwExpWinVer;
    ULONG dwCompatFlags;
    ULONG dwCompatFlags2;
    ULONG dwTIFlags;
    PDESKTOPINFO pDeskInfo;
    ULONGLONG ulClientDelta;
    PHOOK phkCurrent;
    ULONG fsHooks;
    CALLBACKWND CallbackWnd;
    ULONG dwHookCurrent;
    INT cInDDEMLCallback;
    PCLIENTTHREADINFO pClientThreadInfo;
    ULONGLONG dwHookData;
    ULONG dwKeyCache;
    UCHAR afKeyState[8];
    ULONG dwAsyncKeyCache;
    UCHAR afAsyncKeyState[8];
    UCHAR afAsyncKeyStateRecentDown[8];
    HKL__ *hKL;
    USHORT CodePage;
    UCHAR achDbcsCF[2];
    MSG msgDbcsCB;
    ULONG *lpdwRegisteredClasses;
};
struct _VWPL
{
    ULONG cPwnd;
    ULONG cElem;
    ULONG cThreshhold;
    INT fTagged;
    VWPLELEMENT aElement[0];
};
struct _WND
{
    THRDESKHEAD head;
    union
    {
        ULONG state;
        struct
        {
            INT bHasMeun : 1;
            INT bHasVerticalScrollbar : 1;
            INT bHasHorizontalScrollbar : 1;
            INT bHasCaption : 1;
            INT bSendSizeMoveMsgs : 1;
            INT bMsgBox : 1;
            INT bActiveFrame : 1;
            INT bHasSPB : 1;
            INT bNoNCPaint : 1;
            INT bSendEraseBackground : 1;
            INT bEraseBackground : 1;
            INT bSendNCPaint : 1;
            INT bInternalPaint : 1;
            INT bUpdateDirty : 1;
            INT bHiddenPopup : 1;
            INT bForceMenuDraw : 1;
            INT bDialogWindow : 1;
            INT bHasCreatestructName : 1;
            INT bServerSideWindowProc : 1;
            INT bAnsiWindowProc : 1;
            INT bBeingActivated : 1;
            INT bHasPalette : 1;
            INT bPaintNotProcessed : 1;
            INT bSyncPaintPending : 1;
            INT bRecievedQuerySuspendMsg : 1;
            INT bRecievedSuspendMsg : 1;
            INT bToggleTopmost : 1;
            INT bRedrawIfHung : 1;
            INT bRedrawFrameIfHung : 1;
            INT bAnsiCreator : 1;
            INT bMaximizesToMonitor : 1;
            INT bDestroyed : 1;
        };
    };
    union
    {
        ULONG state2;
        struct
        {
            INT bWMPaintSent : 1;
            INT bEndPaintInvalidate : 1;
            INT bStartPaint : 1;
            INT bOldUI : 1;
            INT bHasClientEdge : 1;
            INT bBottomMost : 1;
            INT bFullScreen : 1;
            INT bInDestroy : 1;
            INT bWin31Compat : 1;
            INT bWin40Compat : 1;
            INT bWin50Compat : 1;
            INT bMaximizeMonitorRegion : 1;
            INT bCloseButtonDown : 1;
            INT bMaximizeButtonDown : 1;
            INT bMinimizeButtonDown : 1;
            INT bHelpButtonDown : 1;
            INT bScrollBarLineUpBtnDown : 1;
            INT bScrollBarPageUpBtnDown : 1;
            INT bScrollBarPageDownBtnDown : 1;
            INT bScrollBarLineDownBtnDown : 1;
            INT bAnyScrollButtonDown : 1;
            INT bScrollBarVerticalTracking : 1;
            INT bForceNCPaint : 1;
            INT bForceFullNCPaintClipRgn : 1;
            INT FullScreenMode : 3;
            INT bCaptionTextTruncated : 1;
            INT bNoMinmaxAnimatedRects : 1;
            INT bSmallIconFromWMQueryDrag : 1;
            INT bShellHookRegistered : 1;
            INT bWMCreateMsgProcessed : 1;
        };
    };
    union
    {
        ULONG ExStyle;
        struct
        {
            INT bWS_EX_DLGMODALFRAME : 1;
            INT bUnused1 : 1;
            INT bWS_EX_NOPARENTNOTIFY : 1;
            INT bWS_EX_TOPMOST : 1;
            INT bWS_EX_ACCEPTFILE : 1;
            INT bWS_EX_TRANSPARENT : 1;
            INT bWS_EX_MDICHILD : 1;
            INT bWS_EX_TOOLWINDOW : 1;
            INT bWS_EX_WINDOWEDGE : 1;
            INT bWS_EX_CLIENTEDGE : 1;
            INT bWS_EX_CONTEXTHELP : 1;
            INT bMakeVisibleWhenUnghosted : 1;
            INT bWS_EX_RIGHT : 1;
            INT bWS_EX_RTLREADING : 1;
            INT bWS_EX_LEFTSCROLLBAR : 1;
            INT bUnused2 : 1;
            INT bWS_EX_CONTROLPARENT : 1;
            INT bWS_EX_STATICEDGE : 1;
            INT bWS_EX_APPWINDOW : 1;
            INT bWS_EX_LAYERED : 1;
            INT bWS_EX_NOINHERITLAYOUT : 1;
            INT bUnused3 : 1;
            INT bWS_EX_LAYOUTRTL : 1;
            INT bWS_EX_NOPADDEDBORDER : 1;
            INT bUnused4 : 1;
            INT bWS_EX_COMPOSITED : 1;
            INT bUIStateActive : 1;
            INT bWS_EX_NOACTIVATE : 1;
            INT bWS_EX_COMPOSITEDCompositing : 1;
            INT bRedirected : 1;
            INT bUIStateKbdAccelHidden : 1;
            INT bUIStateFocusRectHidden : 1;
        };
    };
    union
    {
        ULONG style;
        struct
        {
            INT bReserved1 : 16;
            INT bWS_MAXIMIZEBOX : 1;
        };
        struct
        {
            INT bReserved2 : 16;
            INT bWS_TABSTOP : 1;
        };
        struct
        {
            INT bReserved3 : 16;
            INT bUnused5 : 1;
            INT bWS_MINIMIZEBOX : 1;
        };
        struct
        {
            INT bReserved4 : 16;
            INT bUnused6 : 1;
            INT bWS_GROUP : 1;
        };
        struct
        {
            INT bReserved5 : 16;
            INT bUnused7 : 2;
            INT bWS_THICKFRAME : 1;
        };
        struct
        {
            INT bReserved6 : 16;
            INT bUnused8 : 2;
            INT bWS_SIZEBOX : 1;
        };
        struct
        {
            INT bReserved7 : 16;
            INT bUnused9 : 3;
            INT bWS_SYSMENU : 1;
            INT bWS_HSCROLL : 1;
            INT bWS_VSCROLL : 1;
            INT bWS_DLGFRAME : 1;
            INT bWS_BORDER : 1;
            INT bMaximized : 1;
            INT bWS_CLIPCHILDREN : 1;
            INT bWS_CLIPSIBLINGS : 1;
            INT bDisabled : 1;
            INT bVisible : 1;
            INT bMinimized : 1;
            INT bWS_CHILD : 1;
            INT bWS_POPUP : 1;
        };
    };
    VOID *hModule;
    USHORT hMod16;
    USHORT fnid;
    PWND spwndNext;
    PWND spwndPrev;
    PWND spwndParent;
    PWND spwndChild;
    PWND spwndOwner;
    RECT rcWindow;
    RECT rcClient;
    LONGLONG (*lpfnWndProc)(PWND, UINT, ULONGLONG, LONGLONG);
    PCLS pcls;
    HRGN__ *hrgnUpdate;
    PPROPLIST ppropList;
    PSBINFO pSBInfo;
    PMENU spmenuSys;
    PMENU spmenu;
    HRGN__ *hrgnClip;
    HRGN__ *hrgnNewFrame;
    LARGE_UNICODE_STRING strName;
    INT cbwndExtra;
    PWND spwndLastActive;
    HIMC__ *hImc;
    ULONGLONG dwUserData;
    ACTIVATION_CONTEXT *pActCtx;
    PD3DMATRIX pTransform;
    PWND spwndClipboardListenerNext;
    union
    {
        ULONG ExStyle2;
        struct
        {
            INT bClipboardListener : 1;
            INT bLayeredInvalidate : 1;
            INT bRedirectedForPrint : 1;
            INT bLinked : 1;
            INT bLayeredForDWM : 1;
            INT bLayeredLimbo : 1;
            INT bHIGHDPI_UNAWARE_Unused : 1;
            INT bVerticallyMaximizedLeft : 1;
            INT bVerticallyMaximizedRight : 1;
            INT bHasOverlay : 1;
            INT bConsoleWindow : 1;
            INT bChildNoActivate : 1;
        };
    };
};
struct _SVR_INSTANCE_INFO
{
    THROBJHEAD head;
    SVR_INSTANCE_INFO *next;
    SVR_INSTANCE_INFO *nextInThisThread;
    ULONG afCmd;
    PWND spwndEvent;
    VOID *pcii;
};
struct _MENU
{
    PROCDESKHEAD head;
    ULONG fFlags;
    INT iItem;
    UINT cAlloced;
    UINT cItems;
    ULONG cxMenu;
    ULONG cyMenu;
    ULONG cxTextAlign;
    PWND spwndNotify;
    PITEM rgItems;
    PMENULIST pParentMenus;
    ULONG dwContextHelpId;
    ULONG cyMax;
    ULONGLONG dwMenuData;
    HBRUSH__ *hbrBack;
    INT iTop;
    INT iMaxTop;
    ULONG dwArrowsOn : 2;
    UAHMENUPOPUPMETRICS umpm;
};
struct _CALLPROCDATA
{
    PROCDESKHEAD head;
    PCALLPROCDATA spcpdNext;
    ULONGLONG pfnClientPrevious;
    USHORT wType;
};
struct _THREADINFO
{
    ETHREAD *pEThread;
    ULONG RefCount;
    PTL ptlW32;
    VOID *pgdiDcattr;
    VOID *pgdiBrushAttr;
    VOID *pUMPDObjs;
    VOID *pUMPDHeap;
    VOID *pUMPDObj;
    VOID *pProxyPort;
    VOID *pClientID;
    LIST_ENTRY GdiTmpTgoList;
    ULONG pRBRecursionCount;
    ULONG pNonRBRecursionCount;
    TLSPRITESTATE tlSpriteState;
    VOID *pSpriteState;
    VOID *pDevHTInfo;
    ULONG ulDevHTInfoUniqueness;
    VOID *pdcoAA;
    VOID *pdcoRender;
    VOID *pdcoSrc;
    UCHAR bEnableEngUpdateDeviceSurface;
    UCHAR bIncludeSprites;
    ULONG ulWindowSystemRendering;
    ULONG iVisRgnUniqueness;
    PTL ptl;
    PPROCESSINFO ppi;
    PQ pq;
    PKL spklActive;
    PCLIENTTHREADINFO pcti;
    PDESKTOP rpdesk;
    PDESKTOPINFO pDeskInfo;
    ULONGLONG ulClientDelta;
    PCLIENTINFO pClientInfo;
    ULONG TIF_flags;
    UNICODE_STRING *pstrAppName;
    PSMS psmsSent;
    PSMS psmsCurrent;
    PSMS psmsReceiveList;
    LONG timeLast;
    ULONGLONG idLast;
    INT exitCode;
    HDESK__ *hdesk;
    INT cPaintsReady;
    UINT cTimersReady;
    PMENUSTATE pMenuState;
    union
    {
        PTDB ptdb;
        PWINDOWSTATION pwinsta;
    };
    SVR_INSTANCE_INFO *psiiList;
    ULONG dwExpWinVer;
    union
    {
        ULONG dwCompatFlags;
        struct
        {
            UINT IgnoreNoDiscard : 1;
            UINT ForceTextBand : 1;
            UINT UsePrintingEscape : 1;
            UINT IgnoreTopMost : 1;
            UINT CallTTDevice : 1;
            UINT MultipleBands : 1;
            UINT AlwaysSendSyncPaint : 1;
            UINT EditSetTextMunge : 1;
            UINT MoreExtraWndWords : 1;
            UINT TTIgnoreRasterDupe : 1;
            UINT HackWinFlags : 1;
            UINT DealyHwndShakeChk : 1;
            UINT EnumHelv : 1;
            UINT EnumTTNotDevice : 1;
            UINT SubtractClips : 1;
            UINT ForceTTGrapchis : 1;
            UINT NoHRGN1 : 1;
            UINT NcCalcSizeOnMove : 1;
            UINT SendMnuDblClk : 1;
            UINT Win30AvgWidth : 1;
            UINT GetDeviceCaps : 1;
            UINT Winver31 : 1;
            UINT IncreaseStack : 1;
            UINT Win31DevModeSize : 1;
            UINT DisableFontAssoc : 1;
            UINT IgnoreFaults : 1;
            UINT NoEMFSpooling : 1;
            UINT Random31Ux : 1;
            UINT DontJournalAttach : 1;
            UINT DisableDBCSProp : 1;
            UINT SmoothScrolling : 1;
            UINT NoScrollBarCtxMenu : 1;
        };
    };
    union
    {
        ULONG dwCompatFlags2;
        ULONGLONG qwCompatFlags2;
        struct
        {
            ULONGLONG AnimationOff : 1;
            ULONGLONG KCOff : 1;
            ULONGLONG No50ExStyles : 1;
            ULONGLONG NoDrawPatRect : 1;
            ULONGLONG MsShellDlg : 1;
            ULONGLONG NoDDETrackDying : 1;
            ULONGLONG GiveUpForegound : 1;
            ULONGLONG ActiveMenus : 1;
            ULONGLONG EditNoMouseHide : 1;
            ULONGLONG NoBatching : 1;
            ULONGLONG FontSubs : 1;
            ULONGLONG No50ExStyleBits : 1;
            ULONGLONG NoCustomPaperSize : 1;
            ULONGLONG DDE : 1;
            ULONGLONG DefaultCharset : 1;
            ULONGLONG NoCharDeadKey : 1;
            ULONGLONG TryExceptCallWndProc : 1;
            ULONGLONG NoInitFlagsOnFocus : 1;
            ULONGLONG DDENoSync : 1;
            ULONGLONG NoGhost : 1;
            ULONGLONG DDENoAsyncReg : 1;
            ULONGLONG StrictLLHook : 1;
            ULONGLONG NoShadow : 1;
            ULONGLONG ForceFusion : 1;
            ULONGLONG NoTimeCbProtect : 1;
            ULONGLONG DpiAware : 1;
            ULONGLONG OpenGLEMF : 1;
            ULONGLONG TransparentBltMirror : 1;
            ULONGLONG NoPaddedBorder : 1;
            ULONGLONG ForceLegacyResizeNCMetr : 1;
            ULONGLONG HardwareMixer : 1;
            ULONGLONG NoSoftCursOnMoveSize : 1;
            ULONGLONG NoWindowArrangement : 1;
            ULONGLONG SpareCompatFlags2 : 31;
        };
    };
    PQ pqAttach;
    PTHREADINFO ptiSibling;
    PMOVESIZEDATA pmsd;
    ULONG fsHooks;
    PHOOK sphkCurrent;
    LONGLONG lParamHkCurrent;
    ULONGLONG wParamHkCurrent;
    PSBTRACK pSBTrack;
    VOID *hEventQueueClient;
    PKEVENT pEventQueueServer;
    LIST_ENTRY PtiLink;
    INT iCursorLevel;
    POINT ptLast;
    POINT ptLastReal;
    PWND spwndDefaultIme;
    PIMC spDefaultImc;
    HKL__ *hklPrev;
    INT cEnterCount;
    MLIST mlPost;
    USHORT fsChangeBitsRemoved;
    WCHAR wchInjected;
    ULONG fsReserveKeys;
    PKEVENT *apEvent;
    ULONG amdesk;
    UINT cWindows;
    UINT cVisWindows;
    PHOOK aphkStart[16];
    CLIENTTHREADINFO cti;
    VOID *hPrevHidData;
    HTOUCHINPUT__ *hTouchInputCurrent;
    HGESTUREINFO__ *hGestureInfoCurrent;
    MSGPPINFO MsgPPInfo;
    UINT cNestedStableVisRgn;
    LIST_ENTRY readyHead;
    union
    {
        struct
        {
            ULONG fSpecialInitialization : 1;
            ULONG fgfSwitchInProgressSetter : 1;
            ULONG fPack : 26;
            ULONG fThreadCleanupFinished : 1;
            ULONG fETWReserved : 3;
        };
        ULONG ulThreadFlags2;
    };
};
struct _Q
{
    MLIST mlInput;
    PTHREADINFO ptiSysLock;
    ULONGLONG idSysLock;
    ULONGLONG idSysPeek;
    PTHREADINFO ptiMouse;
    PTHREADINFO ptiKeyboard;
    PWND spwndCapture;
    PWND spwndFocus;
    PWND spwndActive;
    PWND spwndActivePrev;
    UINT codeCapture;
    UINT msgDblClk;
    USHORT xbtnDblClk;
    ULONG timeDblClk;
    HWND__ *hwndDblClk;
    POINT ptDblClk;
    POINT ptMouseMove;
    UCHAR afKeyRecentDown[32];
    UCHAR afKeyState[64];
    CARET caret;
    PCURSOR spcurCurrent;
    INT iCursorLevel;
    ULONG QF_flags;
    USHORT cThreads;
    USHORT cLockCount;
    UINT msgJournal;
    LONGLONG ExtraInfo;
    ULONG ulEtwReserved1;
};
struct _HOOK
{
    THRDESKHEAD head;
    PHOOK phkNext;
    INT iHook;
    ULONGLONG offPfn;
    UINT flags;
    INT ihmod;
    PTHREADINFO ptiHooked;
    PDESKTOP rpdesk;
    ULONG nTimeout : 7;
    INT fLastHookHung : 1;
};

typedef struct _DMM_VIDPNPATHSFROMSOURCE_SERIALIZATION
{
    D3DKMDT_VIDPN_SOURCE_MODE SourceMode;
    UCHAR NumPathsFromSource;
    DMM_VIDPNPATHANDTARGETMODE_SERIALIZATION PathAndTargetModeSerialization[1];
} DMM_VIDPNPATHSFROMSOURCE_SERIALIZATION;

typedef struct _OBJECT_TYPE
{
    LIST_ENTRY TypeList;
    UNICODE_STRING Name;
    VOID *DefaultObject;
    UCHAR Index;
    ULONG TotalNumberOfObjects;
    ULONG TotalNumberOfHandles;
    ULONG HighWaterNumberOfObjects;
    ULONG HighWaterNumberOfHandles;
    OBJECT_TYPE_INITIALIZER TypeInfo;
    EX_PUSH_LOCK TypeLock;
    ULONG Key;
    LIST_ENTRY CallbackList;
} OBJECT_TYPE;

typedef struct _TEB
{
    NT_TIB NtTib;
    VOID *EnvironmentPointer;
    CLIENT_ID ClientId;
    VOID *ActiveRpcHandle;
    VOID *ThreadLocalStoragePointer;
    PPEB ProcessEnvironmentBlock;
    ULONG LastErrorValue;
    ULONG CountOfOwnedCriticalSections;
    VOID *CsrClientThread;
    VOID *Win32ThreadInfo;
    ULONG User32Reserved[26];
    ULONG UserReserved[5];
    VOID *WOW32Reserved;
    ULONG CurrentLocale;
    ULONG FpSoftwareStatusRegister;
    VOID *SystemReserved1[54];
    LONG ExceptionCode;
    ACTIVATION_CONTEXT_STACK *ActivationContextStackPointer;
    UCHAR SpareBytes[24];
    ULONG TxFsContext;
    GDI_TEB_BATCH GdiTebBatch;
    CLIENT_ID RealClientId;
    VOID *GdiCachedProcessHandle;
    ULONG GdiClientPID;
    ULONG GdiClientTID;
    VOID *GdiThreadLocalInfo;
    ULONGLONG Win32ClientInfo[62];
    VOID *glDispatchTable[233];
    ULONGLONG glReserved1[29];
    VOID *glReserved2;
    VOID *glSectionInfo;
    VOID *glSection;
    VOID *glTable;
    VOID *glCurrentRC;
    VOID *glContext;
    ULONG LastStatusValue;
    UNICODE_STRING StaticUnicodeString;
    WCHAR StaticUnicodeBuffer[261];
    VOID *DeallocationStack;
    VOID *TlsSlots[64];
    LIST_ENTRY TlsLinks;
    VOID *Vdm;
    VOID *ReservedForNtRpc;
    VOID *DbgSsReserved[2];
    ULONG HardErrorMode;
    VOID *Instrumentation[11];
    GUID ActivityId;
    VOID *SubProcessTag;
    VOID *EtwLocalData;
    VOID *EtwTraceData;
    VOID *WinSockData;
    ULONG GdiBatchCount;
    union
    {
        PROCESSOR_NUMBER CurrentIdealProcessor;
        ULONG IdealProcessorValue;
        struct
        {
            UCHAR ReservedPad0;
            UCHAR ReservedPad1;
            UCHAR ReservedPad2;
            UCHAR IdealProcessor;
        };
    };
    ULONG GuaranteedStackBytes;
    VOID *ReservedForPerf;
    VOID *ReservedForOle;
    ULONG WaitingOnLoaderLock;
    VOID *SavedPriorityState;
    ULONGLONG SoftPatchPtr1;
    VOID *ThreadPoolData;
    VOID **TlsExpansionSlots;
    VOID *DeallocationBStore;
    VOID *BStoreLimit;
    ULONG MuiGeneration;
    ULONG IsImpersonating;
    VOID *NlsCache;
    VOID *pShimData;
    ULONG HeapVirtualAffinity;
    VOID *CurrentTransactionHandle;
    TEB_ACTIVE_FRAME *ActiveFrame;
    VOID *FlsData;
    VOID *PreferredLanguages;
    VOID *UserPrefLanguages;
    VOID *MergedPrefLanguages;
    ULONG MuiImpersonation;
    union
    {
        volatile unsigned short CrossTebFlags;
        USHORT SpareCrossTebBits : 16;
    };
    union
    {
        USHORT SameTebFlags;
        struct
        {
            USHORT SafeThunkCall : 1;
            USHORT InDebugPrint : 1;
            USHORT HasFiberData : 1;
            USHORT SkipThreadAttach : 1;
            USHORT WerInShipAssertCode : 1;
            USHORT RanProcessInit : 1;
            USHORT ClonedThread : 1;
            USHORT SuppressDebugMsg : 1;
            USHORT DisableUserStackWalk : 1;
            USHORT RtlExceptionAttached : 1;
            USHORT InitialThread : 1;
            USHORT SpareSameTebBits : 5;
        };
    };
    VOID *TxnScopeEnterCallback;
    VOID *TxnScopeExitCallback;
    VOID *TxnScopeContext;
    ULONG LockCount;
    ULONG SpareUlong0;
    VOID *ResourceRetValue;
} TEB, *PTEB;

typedef struct _KPCR KPCR, *PKPCR;

struct _KPCR
{
    union
    {
        NT_TIB NtTib;
        struct
        {
            PKGDTENTRY64 GdtBase;
            PKTSS64 TssBase;
            ULONGLONG UserRsp;
            PKPCR Self;
            PKPRCB CurrentPrcb;
            KSPIN_LOCK_QUEUE *LockArray;
            VOID *Used_Self;
        };
    };
    PKIDTENTRY64 IdtBase;
    ULONGLONG Unused[2];
    UCHAR Irql;
    UCHAR SecondLevelCacheAssociativity;
    UCHAR ObsoleteNumber;
    UCHAR Fill0;
    ULONG Unused0[3];
    USHORT MajorVersion;
    USHORT MinorVersion;
    ULONG StallScaleFactor;
    VOID *Unused1[3];
    ULONG KernelReserved[15];
    ULONG SecondLevelCacheSize;
    ULONG HalReserved[16];
    ULONG Unused2;
    VOID *KdVersionBlock;
    VOID *Unused3;
    ULONG PcrAlign1[24];
    KPRCB Prcb;
};

typedef struct _TOUCHINPUTINFO
{
    THROBJHEAD head;
    ULONG dwcInputs;
    UINT uFlags;
    TOUCHINPUT TouchInput[1];
} TOUCHINPUTINFO, *PTOUCHINPUTINFO;

typedef struct _SERVERINFO
{
    ULONG dwSRVIFlags;
    ULONGLONG cHandleEntries;
    LONGLONG (*mpFnidPfn[32])(PWND, UINT, ULONGLONG, LONGLONG, ULONGLONG);
    LONGLONG (*aStoCidPfn[7])(PWND, UINT, ULONGLONG, LONGLONG);
    USHORT mpFnid_serverCBWndProc[31];
    PFNCLIENT apfnClientA;
    PFNCLIENT apfnClientW;
    PFNCLIENTWORKER apfnClientWorker;
    ULONG cbHandleTable;
    USHORT atomSysClass[25];
    ULONG dwDefaultHeapBase;
    ULONG dwDefaultHeapSize;
    UINT uiShellMsg;
    MBSTRING MBStrings[11];
    USHORT atomIconSmProp;
    USHORT atomIconProp;
    USHORT atomContextHelpIdProp;
    USHORT atomFrostedWindowProp;
    CHAR acOemToAnsi[256];
    CHAR acAnsiToOem[256];
    ULONG dwInstalledEventHooks;
    INT aiSysMet[97];
    ULONG argbSystemUnmatched[31];
    ULONG argbSystem[31];
    HBRUSH__ *ahbrSystem[31];
    HBRUSH__ *hbrGray;
    POINT ptCursor;
    POINT ptCursorReal;
    ULONG dwLastRITEventTickCount;
    INT nEvents;
    UINT dtScroll;
    UINT dtLBSearch;
    UINT dtCaretBlink;
    UINT ucWheelScrollLines;
    UINT ucWheelScrollChars;
    INT wMaxLeftOverlapChars;
    INT wMaxRightOverlapChars;
    INT cxSysFontChar;
    INT cySysFontChar;
    TEXTMETRICW tmSysFont;
    DPISERVERINFO dpiSystem;
    HICON__ *hIconSmWindows;
    HICON__ *hIcoWindows;
    ULONG dwKeyCache;
    ULONG dwAsyncKeyCache;
    ULONG cCaptures;
    OEMBITMAPINFO oembmi[93];
    RECT rcScreenReal;
    USHORT BitCount;
    USHORT dmLogPixels;
    UCHAR Planes;
    UCHAR BitsPixel;
    ULONG PUSIFlags;
    UINT uCaretWidth;
    USHORT UILangID;
    ULONG dwLastSystemRITEventTickCountUpdate;
    ULONG adwDBGTAGFlags[35];
    ULONG dwTagCount;
    ULONG dwRIPFlags;
} SERVERINFO, *PSERVERINFO;

typedef struct _DMA_OPERATIONS DMA_OPERATIONS;
typedef struct _DMA_ADAPTER DMA_ADAPTER;

struct _DMA_OPERATIONS
{
    ULONG Size;
    VOID (*PutDmaAdapter)(DMA_ADAPTER *);
    VOID *(*AllocateCommonBuffer)(DMA_ADAPTER *, ULONG, LARGE_INTEGER *, UCHAR);
    VOID (*FreeCommonBuffer)(DMA_ADAPTER *, ULONG, LARGE_INTEGER, VOID *, UCHAR);
    LONG (*AllocateAdapterChannel)(DMA_ADAPTER *, DEVICE_OBJECT *, ULONG, IO_ALLOCATION_ACTION (*)(DEVICE_OBJECT *, PIRP, VOID *, VOID *), VOID *);
    UCHAR (*FlushAdapterBuffers)(DMA_ADAPTER *, PMDL, VOID *, VOID *, ULONG, UCHAR);
    VOID (*FreeAdapterChannel)(DMA_ADAPTER *);
    VOID (*FreeMapRegisters)(DMA_ADAPTER *, VOID *, ULONG);
    LARGE_INTEGER (*MapTransfer)(DMA_ADAPTER *, PMDL, VOID *, VOID *, ULONG *, UCHAR);
    ULONG (*GetDmaAlignment)(DMA_ADAPTER *);
    ULONG (*ReadDmaCounter)(DMA_ADAPTER *);
    LONG (*GetScatterGatherList)(DMA_ADAPTER *, DEVICE_OBJECT *, PMDL, VOID *, ULONG, VOID (*)(DEVICE_OBJECT *, PIRP, SCATTER_GATHER_LIST *, VOID *), VOID *, UCHAR);
    VOID (*PutScatterGatherList)(DMA_ADAPTER *, SCATTER_GATHER_LIST *, UCHAR);
    LONG (*CalculateScatterGatherList)(DMA_ADAPTER *, PMDL, VOID *, ULONG, ULONG *, ULONG *);
    LONG (*BuildScatterGatherList)(DMA_ADAPTER *, DEVICE_OBJECT *, PMDL, VOID *, ULONG, VOID (*)(DEVICE_OBJECT *, PIRP, SCATTER_GATHER_LIST *, VOID *), VOID *, UCHAR, VOID *, ULONG);
    LONG (*BuildMdlFromScatterGatherList)(DMA_ADAPTER *, SCATTER_GATHER_LIST *, PMDL, PMDL *);
};
struct _DMA_ADAPTER
{
    USHORT Version;
    USHORT Size;
    DMA_OPERATIONS *DmaOperations;
};

typedef struct _SHAREDINFO
{
    PSERVERINFO psi;
    PHANDLEENTRY aheList;
    ULONG HeEntrySize;
    PDISPLAYINFO pDispInfo;
    ULONGLONG ulSharedDelta;
    WNDMSG awmControl[31];
    WNDMSG DefWindowMsgs;
    WNDMSG DefWindowSpecMsgs;
} SHAREDINFO, *PSHAREDINFO;

