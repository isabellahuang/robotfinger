file(REMOVE_RECURSE
  "royale_nodelet_automoc.cpp"
  "royale_in_ros_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/tf_generate_messages_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
