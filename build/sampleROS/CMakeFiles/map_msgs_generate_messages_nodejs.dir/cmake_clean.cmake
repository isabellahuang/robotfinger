file(REMOVE_RECURSE
  "royale_in_ros_automoc.cpp"
  "royale_nodelet_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/map_msgs_generate_messages_nodejs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
