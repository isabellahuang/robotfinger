file(REMOVE_RECURSE
  "royale_in_ros_automoc.cpp"
  "royale_nodelet_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/bond_generate_messages_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
