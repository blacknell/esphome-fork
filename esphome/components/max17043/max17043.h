#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace max17043 {

class MAX17043Component : public PollingComponent, public i2c::I2CDevice {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;
  void update() override;
  void sleep_mode();

  void set_voltage_sensor(sensor::Sensor *voltage_sensor) { voltage_sensor_ = voltage_sensor; }
  void set_battery_remaining_sensor(sensor::Sensor *battery_remaining_sensor) {
    battery_remaining_sensor_ = battery_remaining_sensor;
  }
  void set_alert_threshold(int alert_threshold) { this->alert_threshold_ = alert_threshold; }

 protected:
  bool read_data_(uint16_t *raw_voltage, uint16_t *raw_percent);

  sensor::Sensor *voltage_sensor_{nullptr};
  sensor::Sensor *battery_remaining_sensor_{nullptr};
  int alert_threshold_;
};

}  // namespace max17043
}  // namespace esphome
