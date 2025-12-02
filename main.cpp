#include <iostream>
#include <string>
// Задание.
// Создать классы для описания комплектующих компьютеров. Использовать наследование.
// Создавать конструкторы в классах.

#pragma region Классы
class Processing {
public:
    Processing(const std::string &name,
               const std::string &architecture,
               const double &clock_speed,
               const double &performance_rating,
               const double &energy_consumption)

        : m_name{name},
          m_architecture{architecture},
          m_clock_speed{clock_speed},
          m_performance_rating{performance_rating},
          m_energy_consumption{energy_consumption} {
    }

    std::string getName() { return m_name; }
    std::string getArchitecture() { return m_architecture; }
    double getClockSpeed() const { return m_clock_speed; }
    double getPerformance() const { return m_performance_rating; }
    double getEnergyConsumption() const { return m_energy_consumption; }

protected:
    std::string m_name{};
    std::string m_architecture{};
    double m_clock_speed{};
    double m_performance_rating{};
    double m_energy_consumption{};
};

class CentralProcessingUnit : public Processing {
public:
    CentralProcessingUnit(const std::string &name,
                          const std::string &architecture,
                          const double &clock_speed,
                          const double &performance,
                          const double &energy_consumption)

        : Processing{name, architecture, clock_speed, performance, energy_consumption} {
    }

    void outputInformationInConsole() const {
        std::cout << m_name << " information: " << std::endl;
        std::cout << "* Architecture: " << m_architecture << std::endl;
        std::cout << "* Clock speed: " << m_clock_speed << std::endl;
        std::cout << "* Performance rating: " << m_performance_rating << "/10" << std::endl;
        std::cout << "* Energy consumption: " << m_energy_consumption << " Wt" <<  std::endl;
    }
};

class GraphicalProcessingUnit : public Processing {
public:
    GraphicalProcessingUnit(const std::string &name,
                            const std::string &architecture,
                            const double &memory_capacity,
                            const double &clock_speed,
                            const double &performance,
                            const double &energy_consumption)

        : Processing{name, architecture, clock_speed, performance, energy_consumption},
          m_memory_capacity{memory_capacity} {
    }

    double getMemoryCapacity() const { return m_memory_capacity; }

    void outputInformationInConsole() const {
        std::cout << m_name << " information: " << std::endl;
        std::cout << "* Architecture: " << m_architecture << std::endl;
        std::cout << "* Memory capacity: " << m_memory_capacity << std::endl;
        std::cout << "* Clock speed: " << m_clock_speed << std::endl;
        std::cout << "* Performance rating: " << m_performance_rating << "/10" << std::endl;
        std::cout << "* Energy consumption: " << m_energy_consumption << " Wt" << std::endl;
    }

private:
    double m_memory_capacity{};
};

class Memory {
public:
    Memory(const std::string &name,
           const std::string &memory_type,
           const double &memory_capacity_in_gb,
           const double &read_speed,
           const double &write_speed)

        : m_name{name},
          m_memory_type{memory_type},
          m_memory_capacity_in_gb{memory_capacity_in_gb},
          m_read_speed{read_speed},
          m_write_speed{write_speed} {
    }

    std::string getName() const { return m_name; }
    std::string getMemoryType() const { return m_memory_type; }
    double getMemoryCapacity() const { return m_memory_capacity_in_gb; }
    double getReadSpeed() const { return m_read_speed; }
    double getWriteSpeed() const { return m_write_speed; }

protected:
    std::string m_name{};
    std::string m_memory_type{};
    double m_memory_capacity_in_gb{};
    double m_read_speed{};
    double m_write_speed{};
};

class PersistentMemory : public Memory {
public:
    PersistentMemory(const std::string &name,
                     const std::string &memory_type,
                     const double &memory_capacity_in_gb,
                     const double &read_speed,
                     const double &write_speed)

        : Memory(name, memory_type, memory_capacity_in_gb, read_speed, write_speed) {
    }

    void outputInformationInConsole() const {
        std::cout << m_name << " information: " << std::endl;
        std::cout << "* Memory type: " << m_memory_type << std::endl;
        std::cout << "* Memory capacity: " << m_memory_capacity_in_gb << std::endl;
        std::cout << "* Read speed: " << m_read_speed << std::endl;
        std::cout << "* Write speed: " << m_write_speed << std::endl;
    }
};

class OperativeMemory : public Memory {
public:
    OperativeMemory(const std::string &name,
                    const std::string &memory_type,
                    const double &memory_capacity_in_gb,
                    const double &read_speed,
                    const double &write_speed)

        : Memory{name, memory_type, memory_capacity_in_gb, read_speed, write_speed} {
    }

    void outputInformationInConsole() const {
        std::cout << m_name << " information: " << std::endl;
        std::cout << "* Memory capacity: " << m_memory_capacity_in_gb << std::endl;
        std::cout << "* Read speed: " << m_read_speed << std::endl;
        std::cout << "* Write speed: " << m_write_speed << std::endl;
    }
};

class Motherboard {
public:
    Motherboard(const std::string &name,
                const std::string &socket,
                const std::string &chipset,
                const std::string &form_factor)

        : m_name{name},
          m_socket{socket},
          m_chipset{chipset},
          m_form_factor{form_factor} {
    }

    std::string getName() { return m_name; }
    std::string getSocket() const { return m_socket; }
    std::string getChipset() const { return m_chipset; }
    std::string getFormFactor() const { return m_form_factor; }

    void outputInformationInConsole() const {
        std::cout << m_name << " information:" << std::endl;
        std::cout << "* Socket: " << m_socket << std::endl;
        std::cout << "* Chipset: " << m_chipset << std::endl;
        std::cout << "* Form factor: " << m_form_factor << std::endl;
    }

private:
    std::string m_name{};
    std::string m_socket{};
    std::string m_chipset{};
    std::string m_form_factor{};
};

class SupplyUnit {
public:
    SupplyUnit(const std::string &name,
               const std::string &form_factor,
               const double &power_in_watts,
               const int &connector_quantity)

        : m_name{name},
          m_form_factor{form_factor},
          m_power_in_watts{power_in_watts},
          m_connector_quantity{connector_quantity} {
    }

    std::string getName() const { return m_name; }
    std::string getFormFactor() const { return m_form_factor; }
    double getPower() const { return m_power_in_watts; }
    int getConnectorQuantity() const { return m_connector_quantity; }

    void outputInformationInConsole() const {
        std::cout << m_name << " information:" << std::endl;
        std::cout << "* Form factor: " << m_form_factor << std::endl;
        std::cout << "* Power: " << m_power_in_watts << " Wt" << std::endl;
        std::cout << "* Connector quantity: " << m_connector_quantity << std::endl;
    }

private:
    std::string m_name{};
    std::string m_form_factor{};
    double m_power_in_watts{};
    int m_connector_quantity{};
};

class Computer {
public:
    Computer(const CentralProcessingUnit &central_processing_unit,
             const GraphicalProcessingUnit &graphical_processing_unit,
             const PersistentMemory &persistent_memory,
             const OperativeMemory &operative_memory,
             const Motherboard &motherboard,
             const SupplyUnit &supply_unit)

        : m_central_processing_unit(central_processing_unit),
          m_graphical_processing_unit(graphical_processing_unit),
          m_persistent_memory(persistent_memory),
          m_operative_memory(operative_memory),
          m_motherboard(motherboard),
          m_supply_unit(supply_unit)
    {}

    CentralProcessingUnit getCentralProcessingUnit() const { return m_central_processing_unit; }
    GraphicalProcessingUnit getGraphicalProcessingUnit() const { return m_graphical_processing_unit; }
    PersistentMemory getPersistentMemory() const { return m_persistent_memory; }
    OperativeMemory getOperativeMemory() const { return m_operative_memory; }
    Motherboard getMotherboard() const { return m_motherboard; }
    SupplyUnit getSupplyUnit() const { return m_supply_unit; }

    void outputInformationInConsole() const {
        std::cout << "Computer information" << std::endl;
        std::cout << "Central processing unit: " << std::endl;
        m_central_processing_unit.outputInformationInConsole();
        std::cout << "Graphical processing unit: " << std::endl;
        m_graphical_processing_unit.outputInformationInConsole();
        std::cout << "Persistent memory: " << std::endl;
        m_persistent_memory.outputInformationInConsole();
        std::cout << "Operative memory: " << std::endl;
        m_operative_memory.outputInformationInConsole();
        std::cout << "Motherboard: " << std::endl;
        m_motherboard.outputInformationInConsole();
        std::cout << "Supply unit: " << std::endl;
        m_supply_unit.outputInformationInConsole();
    }

private:
    CentralProcessingUnit m_central_processing_unit;
    GraphicalProcessingUnit m_graphical_processing_unit;
    PersistentMemory m_persistent_memory;
    OperativeMemory m_operative_memory;
    Motherboard m_motherboard;
    SupplyUnit m_supply_unit;
};
#pragma endregion

int main() {
    CentralProcessingUnit cpu("Intel i7", "x86", 4.5, 4, 12);
    GraphicalProcessingUnit gpu("Nvidia RTX 4050 mobile", "ADA", 16, 5.5, 6, 12);
    PersistentMemory persistent_memory("Samsung EVA 990 pro", "SSD", 256, 4.5, 5.5);
    OperativeMemory operative_memory("Kingston Fury", "DDR5", 16, 2.4, 2.5);
    Motherboard motherboard("MSI", "LGA 1700", "Z 790", "ATX");
    SupplyUnit supply_unit("KSAS", "Large radius", 0.5, 13);
    Computer computer(cpu, gpu, persistent_memory, operative_memory, motherboard, supply_unit);
    computer.outputInformationInConsole();
}
