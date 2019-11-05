#ifndef __Helpers_H__
#define __Helpers_H__

namespace fw
{
    void OutputMessage(const char* message, ...);
    char* LoadCompleteFile(const char* filename, long* length);
    double GetSystemTime();
    double GetSystemTimeSinceGameStart();

    GLuint LoadTexture(const char* filename);
    void Flip32BitImageVertically(unsigned char* buffer, unsigned int width, unsigned int height);

    template<typename T>
    void Clamp(T& value, T min, T max)
    {
        if (value < min)
            value = min;
        else if (value > max)
            value = max;
    }

} // namespace fw

#endif //__Helpers_H__
