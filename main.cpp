#include <iostream>
#include "windows.h"

#include <vector>
#include <string>

DWORD base = (DWORD)GetModuleHandleA(0);

bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}

DWORD WINAPI main(void* hModule)
{
    //Slider limit bypass
    write_bytes(base + 0x2E5CA, { 0xEB, });
    write_bytes(base + 0x2E5F8, { 0xEB, });
    //Copy Hack
    write_bytes(base + 0x179B8E, { 0x90, 0x90 });
    write_bytes(base + 0x176FE5, { 0xB0 , 0x01 , 0x90 });
    //Level Edit
    write_bytes(base + 0x1E4A32, { 0x90, 0x90 });
    //Custom Object Bypass
    write_bytes(base + 0x7A100, { 0xEB, });
    write_bytes(base + 0x7A022, { 0xEB, });
    write_bytes(base + 0x7A203, { 0x90, 0x90 });
    //Verify Hack
    write_bytes(base + 0x71D48, { 0xEB, });
    //Object Bypass
    write_bytes(base + 0x73169, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x856A4, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87B17, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87BC7, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87D95, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x880F4, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x160B06, { 0xFF, 0xFF, 0xFF, 0x7F });
    //Text Length
    write_bytes(base + 0x21ACB, { 0xEB, 0x04 });
    //Character Filter
    write_bytes(base + 0x21A99, { 0x90, 0x90 });
    //Default Song Bypass
    write_bytes(base + 0x174407, { 0x90, 0x90 });
    write_bytes(base + 0x174411, { 0x90, 0x90, 0x90 });
    write_bytes(base + 0x174456, { 0x90, 0x90 });
    write_bytes(base + 0x174460, { 0x90, 0x90, 0x90 });

    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, main, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
