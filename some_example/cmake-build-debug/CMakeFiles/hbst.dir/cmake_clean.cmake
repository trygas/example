file(REMOVE_RECURSE
  "hbst.pdb"
  "hbst"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/hbst.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
