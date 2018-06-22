file(REMOVE_RECURSE
  "royale_in_ros_automoc.cpp"
  "royale_nodelet_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/nodelet_generate_messages_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
