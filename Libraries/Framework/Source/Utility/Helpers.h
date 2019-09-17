#ifndef __Helpers_H__
#define __Helpers_H__

namespace fw
{
    void OutputMessage(const char* message, ...);
    char* LoadCompleteFile(const char* filename, long* length);
    double GetSystemTime();
    double GetSystemTimeSinceGameStart();

} // namespace fw

#endif //__Helpers_H__
