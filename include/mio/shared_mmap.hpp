#include <stdexcept>
#include <cstdlib>
/* Copyright 2017 https://github.com/mandreyel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MIO_SHARED_MMAP_HEADER
#define MIO_SHARED_MMAP_HEADER

#include "mio/mmap.hpp"

#include <system_error> // std::error_code
#include <memory> // std::shared_ptr

namespace mio {

/**
 * Exposes (nearly) the same interface as `basic_mmap`, but endowes it with
 * `std::shared_ptr` semantics.
 *
 * This is not the default behaviour of `basic_mmap` to avoid allocating on the heap if
 * shared semantics are not required.
 */
template<
    access_mode AccessMode,
    typename ByteT
> class basic_shared_mmap
{
    using impl_type = basic_mmap<AccessMode, ByteT>;
    std::shared_ptr<impl_type> pimpl_;

public:
    using value_type = typename impl_type::value_type;
    using size_type = typename impl_type::size_type;
    using reference = typename impl_type::reference;
    using const_reference = typename impl_type::const_reference;
    using pointer = typename impl_type::pointer;
    using const_pointer = typename impl_type::const_pointer;
    using difference_type = typename impl_type::difference_type;
    using iterator = typename impl_type::iterator;
    using const_iterator = typename impl_type::const_iterator;
    using reverse_iterator = typename impl_type::reverse_iterator;
    using const_reverse_iterator = typename impl_type::const_reverse_iterator;
    using iterator_category = typename impl_type::iterator_category;
    using handle_type = typename impl_type::handle_type;
    using mmap_type = impl_type;

    basic_shared_mmap() = default;
    basic_shared_mmap(const basic_shared_mmap&) = default;
    basic_shared_mmap& operator=(const basic_shared_mmap&) = default;
    basic_shared_mmap(basic_shared_mmap&&) = default;
    basic_shared_mmap& operator=(basic_shared_mmap&&) = default;

    /** Takes ownership of an existing mmap object. */
    basic_shared_mmap(mmap_type&& mmap)
        : pimpl_(std::make_shared<mmap_type>(std::move(mmap)))
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /** Takes ownership of an existing mmap object. */
    basic_shared_mmap& operator=(mmap_type&& mmap)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /** Initializes this object with an already established shared mmap. */
    basic_shared_mmap(std::shared_ptr<mmap_type> mmap) : pimpl_(std::move(mmap)) {
    __builtin_trap() /* STUB: not implemented */;
}

    /** Initializes this object with an already established shared mmap. */
    basic_shared_mmap& operator=(std::shared_ptr<mmap_type> mmap)
    {
    __builtin_trap() /* STUB: not implemented */;
}

#ifdef __cpp_exceptions
    /**
     * The same as invoking the `map` function, except any error that may occur
     * while establishing the mapping is wrapped in a `std::system_error` and is
     * thrown.
     */
    template<typename String>
    basic_shared_mmap(const String& path, const size_type offset = 0, const size_type length = map_entire_file)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * The same as invoking the `map` function, except any error that may occur
     * while establishing the mapping is wrapped in a `std::system_error` and is
     * thrown.
     */
    basic_shared_mmap(const handle_type handle, const size_type offset = 0, const size_type length = map_entire_file)
    {
    __builtin_trap() /* STUB: not implemented */;
}
#endif // __cpp_exceptions

    /**
     * If this is a read-write mapping and the last reference to the mapping,
     * the destructor invokes sync. Regardless of the access mode, unmap is
     * invoked as a final step.
     */
    ~basic_shared_mmap() = default;

    /** Returns the underlying `std::shared_ptr` instance that holds the mmap. */
    std::shared_ptr<mmap_type> get_shared_ptr() {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * On UNIX systems 'file_handle' and 'mapping_handle' are the same. On Windows,
     * however, a mapped region of a file gets its own handle, which is returned by
     * 'mapping_handle'.
     */
    handle_type file_handle() const noexcept
    {
    __builtin_trap() /* STUB: not implemented */;
}

    handle_type mapping_handle() const noexcept
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /** Returns whether a valid memory mapping has been created. */
    bool is_open() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns true if no mapping was established, that is, conceptually the
     * same as though the length that was mapped was 0. This function is
     * provided so that this class has Container semantics.
     */
    bool empty() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * `size` and `length` both return the logical length, i.e. the number of bytes
     * user requested to be mapped, while `mapped_length` returns the actual number of
     * bytes that were mapped which is a multiple of the underlying operating system's
     * page allocation granularity.
     */
    size_type size() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    size_type length() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    size_type mapped_length() const noexcept
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns a pointer to the first requested byte, or `nullptr` if no memory mapping
     * exists.
     */
    template<
        access_mode A = AccessMode,
        typename = typename std::enable_if<A == access_mode::write>::type
    > pointer data() noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_pointer data() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns an iterator to the first requested byte, if a valid memory mapping
     * exists, otherwise this function call is undefined behaviour.
     */
    iterator begin() noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_iterator begin() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_iterator cbegin() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns an iterator one past the last requested byte, if a valid memory mapping
     * exists, otherwise this function call is undefined behaviour.
     */
    template<
        access_mode A = AccessMode,
        typename = typename std::enable_if<A == access_mode::write>::type
    > iterator end() noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_iterator end() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_iterator cend() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns a reverse iterator to the last memory mapped byte, if a valid
     * memory mapping exists, otherwise this function call is undefined
     * behaviour.
     */
    template<
        access_mode A = AccessMode,
        typename = typename std::enable_if<A == access_mode::write>::type
    > reverse_iterator rbegin() noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_reverse_iterator rbegin() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_reverse_iterator crbegin() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns a reverse iterator past the first mapped byte, if a valid memory
     * mapping exists, otherwise this function call is undefined behaviour.
     */
    template<
        access_mode A = AccessMode,
        typename = typename std::enable_if<A == access_mode::write>::type
    > reverse_iterator rend() noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_reverse_iterator rend() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_reverse_iterator crend() const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Returns a reference to the `i`th byte from the first requested byte (as returned
     * by `data`). If this is invoked when no valid memory mapping has been created
     * prior to this call, undefined behaviour ensues.
     */
    reference operator[](const size_type i) noexcept {
    __builtin_trap() /* STUB: not implemented */;
}
    const_reference operator[](const size_type i) const noexcept {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Establishes a memory mapping with AccessMode. If the mapping is unsuccesful, the
     * reason is reported via `error` and the object remains in a state as if this
     * function hadn't been called.
     *
     * `path`, which must be a path to an existing file, is used to retrieve a file
     * handle (which is closed when the object destructs or `unmap` is called), which is
     * then used to memory map the requested region. Upon failure, `error` is set to
     * indicate the reason and the object remains in an unmapped state.
     *
     * `offset` is the number of bytes, relative to the start of the file, where the
     * mapping should begin. When specifying it, there is no need to worry about
     * providing a value that is aligned with the operating system's page allocation
     * granularity. This is adjusted by the implementation such that the first requested
     * byte (as returned by `data` or `begin`), so long as `offset` is valid, will be at
     * `offset` from the start of the file.
     *
     * `length` is the number of bytes to map. It may be `map_entire_file`, in which
     * case a mapping of the entire file is created.
     */
    template<typename String>
    void map(const String& path, const size_type offset,
        const size_type length, std::error_code& error)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Establishes a memory mapping with AccessMode. If the mapping is unsuccesful, the
     * reason is reported via `error` and the object remains in a state as if this
     * function hadn't been called.
     *
     * `path`, which must be a path to an existing file, is used to retrieve a file
     * handle (which is closed when the object destructs or `unmap` is called), which is
     * then used to memory map the requested region. Upon failure, `error` is set to
     * indicate the reason and the object remains in an unmapped state.
     *
     * The entire file is mapped.
     */
    template<typename String>
    void map(const String& path, std::error_code& error)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Establishes a memory mapping with AccessMode. If the mapping is unsuccesful, the
     * reason is reported via `error` and the object remains in a state as if this
     * function hadn't been called.
     *
     * `handle`, which must be a valid file handle, which is used to memory map the
     * requested region. Upon failure, `error` is set to indicate the reason and the
     * object remains in an unmapped state.
     *
     * `offset` is the number of bytes, relative to the start of the file, where the
     * mapping should begin. When specifying it, there is no need to worry about
     * providing a value that is aligned with the operating system's page allocation
     * granularity. This is adjusted by the implementation such that the first requested
     * byte (as returned by `data` or `begin`), so long as `offset` is valid, will be at
     * `offset` from the start of the file.
     *
     * `length` is the number of bytes to map. It may be `map_entire_file`, in which
     * case a mapping of the entire file is created.
     */
    void map(const handle_type handle, const size_type offset,
        const size_type length, std::error_code& error)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * Establishes a memory mapping with AccessMode. If the mapping is unsuccesful, the
     * reason is reported via `error` and the object remains in a state as if this
     * function hadn't been called.
     *
     * `handle`, which must be a valid file handle, which is used to memory map the
     * requested region. Upon failure, `error` is set to indicate the reason and the
     * object remains in an unmapped state.
     *
     * The entire file is mapped.
     */
    void map(const handle_type handle, std::error_code& error)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    /**
     * If a valid memory mapping has been created prior to this call, this call
     * instructs the kernel to unmap the memory region and disassociate this object
     * from the file.
     *
     * The file handle associated with the file that is mapped is only closed if the
     * mapping was created using a file path. If, on the other hand, an existing
     * file handle was used to create the mapping, the file handle is not closed.
     */
    void unmap() {
    __builtin_trap() /* STUB: not implemented */;
}

    void swap(basic_shared_mmap& other) {
    __builtin_trap() /* STUB: not implemented */;
}

    /** Flushes the memory mapped page to disk. Errors are reported via `error`. */
    template<
        access_mode A = AccessMode,
        typename = typename std::enable_if<A == access_mode::write>::type
    > void sync(std::error_code& error) {
    __builtin_trap() /* STUB: not implemented */;
}

    /** All operators compare the underlying `basic_mmap`'s addresses. */

    friend bool operator==(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    friend bool operator!=(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    friend bool operator<(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    friend bool operator<=(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    friend bool operator>(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

    friend bool operator>=(const basic_shared_mmap& a, const basic_shared_mmap& b)
    {
    __builtin_trap() /* STUB: not implemented */;
}

private:
    template<typename MappingToken>
    void map_impl(const MappingToken& token, const size_type offset,
        const size_type length, std::error_code& error)
    {
    __builtin_trap() /* STUB: not implemented */;
}
};

/**
 * This is the basis for all read-only mmap objects and should be preferred over
 * directly using basic_shared_mmap.
 */
template<typename ByteT>
using basic_shared_mmap_source = basic_shared_mmap<access_mode::read, ByteT>;

/**
 * This is the basis for all read-write mmap objects and should be preferred over
 * directly using basic_shared_mmap.
 */
template<typename ByteT>
using basic_shared_mmap_sink = basic_shared_mmap<access_mode::write, ByteT>;

/**
 * These aliases cover the most common use cases, both representing a raw byte stream
 * (either with a char or an unsigned char/uint8_t).
 */
using shared_mmap_source = basic_shared_mmap_source<char>;
using shared_ummap_source = basic_shared_mmap_source<unsigned char>;

using shared_mmap_sink = basic_shared_mmap_sink<char>;
using shared_ummap_sink = basic_shared_mmap_sink<unsigned char>;

} // namespace mio

#endif // MIO_SHARED_MMAP_HEADER
