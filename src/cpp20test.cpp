#include <iostream>
#include <stdexec/execution.hpp>
#include <exec/static_thread_pool.hpp>

int main()
{
    std::cout<<"cpp20test project\n";
    exec::static_thread_pool ctx{2};
    
    auto sch = ctx.get_scheduler();

    auto begin = stdexec::schedule(sch);

    auto hi_again = stdexec::then(begin, []{ 
        std::cout<<"hi again \n";
        return 13;
    });

    auto add_42 = stdexec::then(hi_again, [](int arg) { return arg + 42; });

    auto [i] = stdexec::sync_wait(std::move(add_42)).value();
    std::cout << "Result: " << i << std::endl;

    return 0;
}