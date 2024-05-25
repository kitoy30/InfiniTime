#pragma once

#include <array>
#include <memory>
#include "displayapp/screens/Screen.h"
#include "displayapp/screens/ScreenList.h"
#include "displayapp/screens/Symbols.h"
#include "displayapp/screens/List.h"

namespace Pinetime {

  namespace Applications {
    namespace Screens {

      class Settings : public Screen {
      public:
        Settings(DisplayApp* app, Pinetime::Controllers::Settings& settingsController);
        ~Settings() override;

        bool OnTouchEvent(Pinetime::Applications::TouchEvents event) override;

      private:
        DisplayApp* app;
        auto CreateScreenList() const;
        std::unique_ptr<Screen> CreateScreen(unsigned int screenNum) const;

        Controllers::Settings& settingsController;

        static constexpr int entriesPerScreen = 4;

        // Increment this when more space is needed
        static constexpr int nScreens = 4;

        static constexpr std::array<List::Applications, entriesPerScreen * nScreens> entries {{
          {Symbols::sun, "Affichage", Apps::SettingDisplay},
          {Symbols::eye, "Réveil", Apps::SettingWakeUp},
          {Symbols::clock, "Format heure", Apps::SettingTimeFormat},
          {Symbols::home, "Apparence", Apps::SettingWatchFace},

          {Symbols::shoe, "Podomètre", Apps::SettingSteps},
          {Symbols::clock, "Date&Heure", Apps::SettingSetDateTime},
          {Symbols::cloudSunRain, "Météo", Apps::SettingWeatherFormat},
          {Symbols::batteryHalf, "Batterie", Apps::BatteryInfo},

          {Symbols::clock, "Sonnerie", Apps::SettingChimes},
          {Symbols::tachometer, "Calib. mouv.", Apps::SettingShakeThreshold},
          {Symbols::check, "Micrologiciel", Apps::FirmwareValidation},
          {Symbols::bluetooth, "Bluetooth", Apps::SettingBluetooth},

          {Symbols::list, "A propos", Apps::SysInfo},

          // {Symbols::none, "None", Apps::None},
          // {Symbols::none, "None", Apps::None},
          // {Symbols::none, "None", Apps::None},
          // {Symbols::none, "None", Apps::None},

        }};
        ScreenList<nScreens> screens;
      };
    }
  }
}
