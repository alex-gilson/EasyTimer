


add_executable(EasyTimerTs
				EasyTimerTs.cpp
)

target_include_directories(EasyTimerTs PRIVATE .)

target_link_libraries(EasyTimerTs PRIVATE EasyTimer pthread)