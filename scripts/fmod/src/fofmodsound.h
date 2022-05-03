#ifndef __FOFMOD_SOUND_H__
#define __FOFMOD_SOUND_H__


#include "fofmoddef.h"
#include "refcount.h"
#include "cachedata.h"

namespace FOFMOD
{
	class System;
	
	class CacheSoundData;
	typedef std::map< std::string, CacheSoundData* > CachedDataMap;
	
	class Sound : public IRefcountable
	{
		protected:
			unsigned int refcount;

		public:
			FMOD::Sound*   handle;
			FOFMOD::CacheSoundData* cacheData;
			Sound();
			Sound( FMOD::Sound* handle );
			~Sound();
			bool IsValid();
			void Addref() override;
			void Release() override;
			void SetCache( FOFMOD::CacheSoundData* cdata );
			void SetHandle( FMOD::Sound* snd );
			unsigned int GetLength();
			void SetLoopCount( int loopCount );
			int GetLoopCount();

	};

	// Angelscript interfacing for type methods
	extern void Script_Sound_Addref( FOFMOD::Sound* ptr );
	extern void Script_Sound_Release( FOFMOD::Sound* ptr );
	extern unsigned int Script_Sound_GetLength( FOFMOD::Sound* ptr );
	extern void	Script_Sound_SetLoopCount( int loopCount, FOFMOD::Sound* ptr ); // -1 for forever
	extern int  Script_Sound_GetLoopCount( FOFMOD::Sound* ptr );
	extern bool Script_Sound_IsValid( FOFMOD::Sound* ptr );
};

#endif // __FOFMOD_SOUND_H__