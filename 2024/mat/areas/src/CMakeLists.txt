add_executable(areas 
    apto.cpp
    apto.hpp
    csv.hpp
    csv.cpp
    eval.hpp
    eval.cpp
    main.cpp
)

target_link_libraries(areas fmt::fmt)
