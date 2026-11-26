#include "../include/IncomeSource.h"
IncomeSource::IncomeSource()
    : id(""),
      name("")
{}
IncomeSource::IncomeSource(
    const std::string& id,
    const std::string& name)
    : id(id),
      name(name)
{}
const std::string& IncomeSource::getId() const
{
    return id;
}
void IncomeSource::setId(
    const std::string& id)
{
    this->id = id;
}
const std::string& IncomeSource::getName() const
{
    return name;
}
void IncomeSource::setName(
    const std::string& name)
{
    this->name = name;
}
