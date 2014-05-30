/*
 Copyright (c) 2008 TrueCrypt Foundation. All rights reserved.

 Governed by the TrueCrypt License 2.8 the full text of which is contained
 in the file License.txt included in TrueCrypt binary and source code
 distribution packages.
*/

#include "CoreException.h"
#include "Platform/SerializerFactory.h"

namespace TrueCrypt
{
	void ElevationFailed::Deserialize (shared_ptr <Stream> stream)
	{
		ExecutedProcessFailed::Deserialize (stream);
	}

	void ElevationFailed::Serialize (shared_ptr <Stream> stream) const
	{
		ExecutedProcessFailed::Serialize (stream);
	}

#define TC_EXCEPTION(TYPE) TC_SERIALIZER_FACTORY_ADD(TYPE)
#undef TC_EXCEPTION_NODECL
#define TC_EXCEPTION_NODECL(TYPE) TC_SERIALIZER_FACTORY_ADD(TYPE)

	TC_SERIALIZER_FACTORY_ADD_EXCEPTION_SET (CoreException);
}
