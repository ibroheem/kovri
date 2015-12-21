#include "Daemon.h"
#include "core/util/Log.h"

#ifdef _WIN32

#include "Win32Service.h"

namespace i2p
{
    namespace util
    {
        bool DaemonWin32::Init()
        {
            setlocale(LC_CTYPE, "");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            setlocale(LC_ALL, "Russian");

            if (!Daemon_Singleton::Init()) return false;
            if (I2PService::isService())
                m_isDaemon = 1;
            else
                m_isDaemon = 0;

            std::string serviceControl = i2p::util::config::varMap["service"].as<std::string>();
            if (serviceControl == "install")
            {
                InstallService(
                    SERVICE_NAME,               // Name of service
                    SERVICE_DISPLAY_NAME,       // Name to display
                    SERVICE_START_TYPE,         // Service start type
                    SERVICE_DEPENDENCIES,       // Dependencies
                    SERVICE_ACCOUNT,            // Service running account
                    SERVICE_PASSWORD            // Password of the account
                    );
                exit(0);
            }
            else if (serviceControl == "remove")
            {
                UninstallService(SERVICE_NAME);
                exit(0);
            }
            else if (serviceControl != "none")
            {
                printf(" --service=install  to install the service.\n");
                printf(" --service=remove   to remove the service.\n");
            }
            
            if (m_isDaemon == 1)
            {
                LogPrint("Service session");
                I2PService service(SERVICE_NAME);
                if (!I2PService::Run(service))
                {
                    LogPrint("Service failed to run w/err 0x%08lx\n", GetLastError());
                    exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
            }
            else
                LogPrint("User session");

            return true;
        }
        bool DaemonWin32::Start()
        {
            setlocale(LC_CTYPE, "");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            setlocale(LC_ALL, "Russian");

            return Daemon_Singleton::Start();
        }

        bool DaemonWin32::Stop()
        {
            return Daemon_Singleton::Stop();
        }
    }
}

#endif
