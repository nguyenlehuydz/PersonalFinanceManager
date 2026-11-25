#ifndef EXPENSECATEGORY_H
#define EXPENSECATEGORY_H
#include <string>
class ExpenseCategory
{
private:
    std::string id;
    std::string name;
public:
    ExpenseCategory();
    ExpenseCategory(
        const std::string& id,
        const std::string& name);
    const std::string& getId() const;
    void setId(const std::string& id);
    const std::string& getName() const;
    void setName(const std::string& name);
};
#endif
