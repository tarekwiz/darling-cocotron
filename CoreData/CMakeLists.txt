project(CoreData)

include(darling_framework)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
	-include math.h \
	-include stdlib.h \
	-include CoreFoundation/CoreFoundation.h \
	-include Foundation/Foundation.h \
	-Wno-nonportable-include-path \
	-Wno-deprecated-objc-isa-usage \
	-mmacosx-version-min=10.10"
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/external/foundation/include
	${CMAKE_SOURCE_DIR}/src/external/foundation/include/Foundation
	${CMAKE_SOURCE_DIR}/src/external/corefoundation
	${CMAKE_SOURCE_DIR}/src/external/objc4/runtime
	${CMAKE_SOURCE_DIR}/src/external/libclosure
	${CMAKE_SOURCE_DIR}/src/external/security/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/private_include
	${CMAKE_SOURCE_DIR}/src/launchd/liblaunch
	${CMAKE_SOURCE_DIR}/src/libmalloc/include
	${CMAKE_SOURCE_DIR}/src/copyfile
	${CMAKE_SOURCE_DIR}/src/libc/gen
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/i18n
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/common
	${CMAKE_SOURCE_DIR}/src/external/libxml2/include
	${CMAKE_BINARY_DIR}/src/external/libxml2/include

	${CMAKE_CURRENT_SOURCE_DIR}
)

set(CoreData_sources
    CoreDataErrors.m
    # dllmain.m
    NSAtomicStoreCacheNode.m
    NSAtomicStore.m
    NSAttributeDescription.m
    NSEntityDescription.m
    NSFetchedPropertyDescription.m
    NSFetchRequest.m
    NSInMemoryPersistentStore.m
    NSManagedObjectContext.m
    NSManagedObjectID.m
    NSManagedObject.m
    NSManagedObjectModel.m
    NSManagedObjectMutableSet.m
    NSManagedObjectSetEnumerator.m
    NSManagedObjectSet.m
    NSPersistentStoreCoordinator.m
    NSPersistentStore.m
    NSPropertyDescription.m
    NSRelationshipDescription.m
    NSXMLPersistentStore.m
)

set_source_files_properties(${CoreData_sources} LANGUAGE C)

set(DYLIB_COMPAT_VERSION "1.0.0")
set(DYLIB_CURRENT_VERSION "752.0.0")

add_framework(CoreData
	FAT
	CURRENT_VERSION
	SOURCES
		${CoreData_sources}
	VERSION "A"
	DEPENDENCIES
		objc
		system
		${CoreFoundation}
		Foundation
)
