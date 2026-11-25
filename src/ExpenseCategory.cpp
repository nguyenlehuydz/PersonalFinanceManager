#include "../include/ExpenseCategory.h"
ExpenseCategory::ExpenseCategory()
    : id(""),
      name("")
{}
ExpenseCategory::ExpenseCategory(
    const std::string& id,
    const std::string& name)
    : id(id),
      name(name)
{}
const std::string& ExpenseCategory::getId() const
{
    return id;
}
void ExpenseCategory::setId(
    const std::string& id)
{
    this->id = id;
}
const std::string& ExpenseCategory::getName() const
{
    return name;
}
void ExpenseCategory::setName(
    const std::string& name)
{
    this->name = name;
}
