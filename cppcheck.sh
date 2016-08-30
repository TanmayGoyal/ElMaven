# cppcheck -j $(nproc) --enable=all --suppress='*:libcdfread/*' --suppress='*:libneural/*' --suppress='*:Eigen/*' --suppress='*:libcsvparser/*' --suppress='*:pugixml/*' --suppress='*:mzWatcher/*' --inconclusive --xml --xml-version=2 * 2> cppcheck.xml
cppcheck -j $(nproc) --enable=all -itest/ -ilibcdfread/ -ilibneural/ -iEigen/ -ilibcsvparser/ -ipugixml/ -imzWatcher/ -ilibpls/ --inconclusive --xml --xml-version=2 * 2> cppcheck.xml
