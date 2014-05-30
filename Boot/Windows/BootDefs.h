/*
 Copyright (c) 2008 TrueCrypt Foundation. All rights reserved.

 Governed by the TrueCrypt License 2.5 the full text of which is contained
 in the file License.txt included in TrueCrypt binary and source code
 distribution packages.
*/

#ifndef TC_HEADER_Boot_BootDefs
#define TC_HEADER_Boot_BootDefs

// Total memory required (CODE + DATA + BSS + STACK + 0x100) in KBytes - determined from linker map.
#define TC__BOOT_MEMORY_REQUIRED	42

#ifdef TC_WINDOWS_BOOT_SINGLE_CIPHER_MODE
#	undef TC__BOOT_MEMORY_REQUIRED

#	ifdef TC_WINDOWS_BOOT_AES
#		ifdef TC_WINDOWS_BOOT_RESCUE_DISK_MODE
#			define TC__BOOT_MEMORY_REQUIRED	28
#		else
#			define TC__BOOT_MEMORY_REQUIRED	27
#		endif
#	elif defined (TC_WINDOWS_BOOT_SERPENT)
#		define TC__BOOT_MEMORY_REQUIRED		32
#	elif defined (TC_WINDOWS_BOOT_TWOFISH)
#		define TC__BOOT_MEMORY_REQUIRED		40
#	endif

#endif

// Windows Vista boot loader uses memory up to 8000:FFFF, disregarding the BIOS memory map and the amount
// of available memory at 40:0013. Therefore, the code has to be loaded at or above 9000:0000.

// Modifying this value can introduce incompatibility with previous versions
#define TC__BOOT_LOADER_SEGMENT TC_HEX (9000)
#define TC__COM_EXECUTABLE_OFFSET TC_HEX (100)

#define TC__BOOT_LOADER_LOWMEM_SEGMENT TC_HEX (2000)
#define TC__BOOT_LOADER_BUFFER_SEGMENT TC_HEX (5000)

#define TC__BOOT_LOADER_STACK_TOP (TC_BOOT_MEMORY_REQUIRED * TC_UNSIGNED (1024) - 4)

#define TC__LB_SIZE 512
#define TC__BOOT_LOADER_AREA_SECTOR_COUNT 63

#define TC__BOOT_SECTOR_LOADER_LENGTH_OFFSET 432
#define TC__BOOT_SECTOR_LOADER_CHECKSUM_OFFSET 434
#define TC__BOOT_SECTOR_CONFIG_OFFSET 439	// The last byte that is reserved for the boot loader

#define TC__BOOT_LOADER_DECOMPRESSOR_START_SECTOR 2
#define TC__BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT 4
#define TC__BOOT_LOADER_DECOMPRESSOR_MEMORY_SIZE 32768
#define TC__BOOT_LOADER_COMPRESSED_BUFFER_OFFSET (TC_COM_EXECUTABLE_OFFSET + 3072)

#define TC__BOOT_LOADER_START_SECTOR (TC_BOOT_LOADER_DECOMPRESSOR_START_SECTOR + TC_BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT)
#define TC__MAX_BOOT_LOADER_SECTOR_COUNT (TC_BOOT_LOADER_AREA_SECTOR_COUNT - TC_BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT - 2)
#define TC__MAX_BOOT_LOADER_DECOMPRESSED_SIZE ((TC_BOOT_LOADER_AREA_SECTOR_COUNT - 2) * TC_LB_SIZE)

#define TC__BOOT_LOADER_BACKUP_SECTOR_COUNT 30

#define TC__GZIP_HEADER_SIZE 10

#define TC__BOOT_CFG_FLAG_AREA_SIZE	1	// In bytes

// If you add more flags, revise TC__BOOT_CFG_FLAG_AREA_SIZE
#define TC__BOOT_CFG_FLAG_BACKUP_LOADER_AVAILABLE		TC_HEX (02)
#define TC__BOOT_CFG_FLAG_WINDOWS_VISTA_OR_LATER		TC_HEX (04)
#define TC__BOOT_CFG_FLAG_RESCUE_DISK_ORIG_SYS_LOADER	TC_HEX (20)

#define TC__BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE		(TC_HEX (40) + TC_HEX (80))

// The following items are treated as a 2-bit value (apply TC_BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE to obtain the value)
#define TC__HIDDEN_OS_CREATION_PHASE_NONE		0
#define TC__HIDDEN_OS_CREATION_PHASE_CLONING	TC_HEX (40)		// The boot loader is to copy the content of the system partition to the hidden volume
#define TC__HIDDEN_OS_CREATION_PHASE_DECOY_OS	TC_HEX (80)		// The boot loader has successfully copied the content of the system partition to the hidden volume (the decoy OS is to be encrypted now)
#define TC__HIDDEN_OS_CREATION_PHASE_RESERVED	(TC_HEX (40) + TC_HEX (80))		// Reserved for possible future use


#ifdef TC_ASM_PREPROCESS

#define TC_HEX(N) 0##N##h
#define TC_UNSIGNED(N) N

TC_BOOT_MEMORY_REQUIRED = TC__BOOT_MEMORY_REQUIRED
TC_BOOT_LOADER_SEGMENT = TC__BOOT_LOADER_SEGMENT
TC_COM_EXECUTABLE_OFFSET = TC__COM_EXECUTABLE_OFFSET
TC_BOOT_LOADER_LOWMEM_SEGMENT = TC__BOOT_LOADER_LOWMEM_SEGMENT
TC_BOOT_LOADER_BUFFER_SEGMENT = TC__BOOT_LOADER_BUFFER_SEGMENT
TC_BOOT_LOADER_STACK_TOP = TC__BOOT_LOADER_STACK_TOP
TC_LB_SIZE = TC__LB_SIZE
TC_BOOT_LOADER_AREA_SECTOR_COUNT = TC__BOOT_LOADER_AREA_SECTOR_COUNT
TC_BOOT_SECTOR_LOADER_LENGTH_OFFSET = TC__BOOT_SECTOR_LOADER_LENGTH_OFFSET
TC_BOOT_SECTOR_LOADER_CHECKSUM_OFFSET = TC__BOOT_SECTOR_LOADER_CHECKSUM_OFFSET
TC_BOOT_SECTOR_CONFIG_OFFSET = TC__BOOT_SECTOR_CONFIG_OFFSET
TC_BOOT_LOADER_DECOMPRESSOR_START_SECTOR = TC__BOOT_LOADER_DECOMPRESSOR_START_SECTOR
TC_BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT = TC__BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT
TC_BOOT_LOADER_DECOMPRESSOR_MEMORY_SIZE = TC__BOOT_LOADER_DECOMPRESSOR_MEMORY_SIZE
TC_BOOT_LOADER_COMPRESSED_BUFFER_OFFSET = TC__BOOT_LOADER_COMPRESSED_BUFFER_OFFSET
TC_BOOT_LOADER_START_SECTOR = TC__BOOT_LOADER_START_SECTOR
TC_MAX_BOOT_LOADER_SECTOR_COUNT = TC__MAX_BOOT_LOADER_SECTOR_COUNT
TC_MAX_BOOT_LOADER_DECOMPRESSED_SIZE = TC__MAX_BOOT_LOADER_DECOMPRESSED_SIZE
TC_BOOT_LOADER_BACKUP_SECTOR_COUNT = TC__BOOT_LOADER_BACKUP_SECTOR_COUNT
TC_GZIP_HEADER_SIZE = TC__GZIP_HEADER_SIZE
TC_BOOT_CFG_FLAG_AREA_SIZE = TC__BOOT_CFG_FLAG_AREA_SIZE
TC_BOOT_CFG_FLAG_BACKUP_LOADER_AVAILABLE = TC__BOOT_CFG_FLAG_BACKUP_LOADER_AVAILABLE
TC_BOOT_CFG_FLAG_WINDOWS_VISTA_OR_LATER = TC__BOOT_CFG_FLAG_WINDOWS_VISTA_OR_LATER
TC_BOOT_CFG_FLAG_RESCUE_DISK_ORIG_SYS_LOADER = TC__BOOT_CFG_FLAG_RESCUE_DISK_ORIG_SYS_LOADER
TC_BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE = TC__BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE
TC_HIDDEN_OS_CREATION_PHASE_NONE = TC__HIDDEN_OS_CREATION_PHASE_NONE
TC_HIDDEN_OS_CREATION_PHASE_CLONING = TC__HIDDEN_OS_CREATION_PHASE_CLONING
TC_HIDDEN_OS_CREATION_PHASE_DECOY_OS = TC__HIDDEN_OS_CREATION_PHASE_DECOY_OS

#else // TC_ASM_PREPROCESS

#define TC_HEX(N) 0x##N
#define TC_UNSIGNED(N) N##U

#define TC_BOOT_MEMORY_REQUIRED TC__BOOT_MEMORY_REQUIRED
#define TC_BOOT_LOADER_SEGMENT TC__BOOT_LOADER_SEGMENT
#define TC_COM_EXECUTABLE_OFFSET TC__COM_EXECUTABLE_OFFSET
#define TC_BOOT_LOADER_LOWMEM_SEGMENT TC__BOOT_LOADER_LOWMEM_SEGMENT
#define TC_BOOT_LOADER_BUFFER_SEGMENT TC__BOOT_LOADER_BUFFER_SEGMENT
#define TC_BOOT_LOADER_STACK_TOP (TC__BOOT_LOADER_STACK_TOP)
#define TC_BOOT_LOADER_AREA_SECTOR_COUNT TC__BOOT_LOADER_AREA_SECTOR_COUNT
#define TC_BOOT_SECTOR_LOADER_LENGTH_OFFSET TC__BOOT_SECTOR_LOADER_LENGTH_OFFSET
#define TC_BOOT_SECTOR_LOADER_CHECKSUM_OFFSET TC__BOOT_SECTOR_LOADER_CHECKSUM_OFFSET
#define TC_BOOT_LOADER_DECOMPRESSOR_START_SECTOR TC__BOOT_LOADER_DECOMPRESSOR_START_SECTOR
#define TC_BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT TC__BOOT_LOADER_DECOMPRESSOR_SECTOR_COUNT
#define TC_BOOT_SECTOR_CONFIG_OFFSET TC__BOOT_SECTOR_CONFIG_OFFSET
#define TC_BOOT_LOADER_START_SECTOR TC__BOOT_LOADER_START_SECTOR
#define TC_LB_SIZE TC__LB_SIZE
#define TC_MAX_BOOT_LOADER_SECTOR_COUNT TC__MAX_BOOT_LOADER_SECTOR_COUNT
#define TC_MAX_BOOT_LOADER_DECOMPRESSED_SIZE TC__MAX_BOOT_LOADER_DECOMPRESSED_SIZE
#define TC_BOOT_LOADER_BACKUP_SECTOR_COUNT TC__BOOT_LOADER_BACKUP_SECTOR_COUNT
#define TC_GZIP_HEADER_SIZE TC__GZIP_HEADER_SIZE
#define TC_BOOT_CFG_FLAG_AREA_SIZE TC__BOOT_CFG_FLAG_AREA_SIZE
#define TC_BOOT_CFG_FLAG_BACKUP_LOADER_AVAILABLE TC__BOOT_CFG_FLAG_BACKUP_LOADER_AVAILABLE
#define TC_BOOT_CFG_FLAG_WINDOWS_VISTA_OR_LATER TC__BOOT_CFG_FLAG_WINDOWS_VISTA_OR_LATER
#define TC_BOOT_CFG_FLAG_RESCUE_DISK_ORIG_SYS_LOADER TC__BOOT_CFG_FLAG_RESCUE_DISK_ORIG_SYS_LOADER
#define TC_BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE TC__BOOT_CFG_MASK_HIDDEN_OS_CREATION_PHASE
#define TC_HIDDEN_OS_CREATION_PHASE_NONE TC__HIDDEN_OS_CREATION_PHASE_NONE
#define TC_HIDDEN_OS_CREATION_PHASE_CLONING TC__HIDDEN_OS_CREATION_PHASE_CLONING
#define TC_HIDDEN_OS_CREATION_PHASE_DECOY_OS TC__HIDDEN_OS_CREATION_PHASE_DECOY_OS

#endif // TC_ASM_PREPROCESS

#endif // TC_HEADER_Boot_BootDefs
