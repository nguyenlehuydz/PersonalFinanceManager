#ifndef INCOMESOURCE_H
#define INCOMESOURCE_H
#include <string>
class IncomeSource
{
private:
    std::string id;
    std::string name;
public:
    IncomeSource();
    IncomeSource(
        const std::string& id,
        const std::string& name);
    const std::string& getId() const;
    void setId(const std::string& id);
    const std::string& getName() const;
    void setName(const std::string& name);
};
#endif
