#pragma once

template<typename ...Args>
constexpr void print(Args&&... args) noexcept
{
   ((std::cout << std::forward<Args>(args) << " "), ...);
}

void newLine();