from setuptools import setup, Extension

coolctl_module = Extension(
    "coolctl.coolctl",
    sources=["coolctl/coolctlmodule.c"]
)

setup(
    name="coolctl",
    version="0.1",
    description="Proof-of-concept cooling control bindings for Python",
    packages=["coolctl"],
    ext_modules=[coolctl_module],
)
