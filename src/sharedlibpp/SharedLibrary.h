/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef SHAREDLIBPP_SHAREDLIBRARY_H
#define SHAREDLIBPP_SHAREDLIBRARY_H

#include <sharedlibpp/api.h>
#include <string>

namespace sharedlibpp {

/**
 * Low-level wrapper for loading shared libraries (DLLs) and accessing
 * symbols within it.
 */
class SHLIBPP_API SharedLibrary
{
public:
    /**
     * Initialize, without opening a shared library yet.
     */
    SharedLibrary();

    /**
     * Load the named shared library / DLL.
     *
     * @param filename name of file (see open method)
     */
    SharedLibrary(const char *filename);

    /**
     * Destructor.  Will close() if needed.
     */
    virtual ~SharedLibrary();

    SharedLibrary(const SharedLibrary& rhs) = delete;
    SharedLibrary(SharedLibrary&& rhs) noexcept = delete;
    SharedLibrary& operator=(const SharedLibrary& rhs) = delete;
    SharedLibrary& operator=(SharedLibrary&& rhs) noexcept = delete;

    /**
     * Load the named shared library / DLL.  The library is found
     * using the algoithm of ACE::ldfind.  Operating-system-specific
     * extensions will be tried, and the relevant path for shared
     * libraries.
     *
     * @param filename name of file.
     * @return true on success
     */
    bool open(const char *filename);

    /**
     * Shared library no longer needed, unload if not in use elsewhere.
     * @return true on success
     */
    bool close();

    /**
     * Returns a human-readable string describing the most recent error that
     * occurred from a call to one of its functions.
     *
     * @return the most recent error
     */
    std::string error();

    /**
     * Look up a symbol in the shared library.
     */
    void *getSymbol(const char *symbolName);

    /**
     * Check if the shared library is valid
     *
     * @return true iff a valid library has been loaded.
     */
    bool isValid() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
    class SHLIBPP_HIDDEN Private;
    Private* mPriv;
#endif
};

} // namespace sharedlibpp

#endif // SHAREDLIBPP_SHAREDLIBRARY_H
