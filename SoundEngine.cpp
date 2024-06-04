#include <assert.h>
#include "SoundEngine.h"

SoundEngine* SoundEngine::m_s_soundEngineInstance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_soundEngineInstance == nullptr);
	m_s_soundEngineInstance = this;
	m_clickBuffer.loadFromFile("sound/click.ogg");
	m_clickSound.setBuffer(m_clickBuffer);
}

void SoundEngine::playClick()
{
	m_s_soundEngineInstance->m_clickSound.play();
}
