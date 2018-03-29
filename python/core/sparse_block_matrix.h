#include <pybind11/pybind11.h>

#include <g2o/core/sparse_block_matrix.h>


namespace py = pybind11;
using namespace pybind11::literals;


namespace g2o {

namespace {
    template<class MatrixType=MatrixX>
    void templatedSparseBlockMatrix(py::module& m, const std::string& suffix) {
        using CLS = SparseBlockMatrix<MatrixType>;

        py::class_<CLS>(m, ("SparseBlockMatrix" + suffix).c_str())
            .def(py::init<>())
            .def("clear", &CLS::clear, "dealloc"_a=false)
            .def("cols", &CLS::cols)
            .def("rows", &CLS::rows)
            .def("block", (const MatrixType* (CLS::*) (int, int) const) &CLS::block,
                "r"_a, "c"_a)

            // TODO

        ;
    }
}



void declareSparseBlockMatrix(py::module& m) {

    templatedSparseBlockMatrix<MatrixX>(m, "X");

}

}
