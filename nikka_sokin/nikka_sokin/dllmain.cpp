#include "pch.h"
#include "CustomAPI.h"
#include <thread>
#include <string>

using conhostprint_t = void(*)(std::string, std::string);



    BOOL APIENTRY DllMain(HMODULE hModule,
        DWORD ul_reason_for_call,
        LPVOID lpReserved)
    {
        switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            std::thread([&] {
                MessageBoxA(NULL, "Successful Injected", "dev-sokin.xyz", MB_OK);
                auto conhostprint = (conhostprint_t)(CustomAPI::GetExportAddress((HMODULE)CustomAPI::GetModuleA("conhost-v2.dll"), "?Print@ConHost@@YAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0@Z", true));

                do {
                    conhostprint("SOKIN ON TOP ", " ISOLATED BITCH , I LOVE MY l1k#8935 , discord.gg/sokin                                                                                                             ");
                } while (true); //true - all prining in console / false - only 1 print 

                }).detach();
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        }
        return TRUE;
    }






























    //STOP PASTING FUCKING GAY [CREDIT BY SOKIN#9999]