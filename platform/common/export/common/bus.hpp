//!
//! \file
//! \brief \todo
//! \copyright
//!

#ifndef PLATFORM_COMMON_BUS_
#define PLATFORM_COMMON_BUS_

#include <ecl/err.hpp>

#include <functional>


namespace ecl
{

//! Channels of a bus.
enum class bus_channel
{
    rx,         //!< Receive channel.
    tx,         //!< Transmit channel.
    meta,       //!< Meta-channel.
};

//! Various events.
enum class bus_event
{
    ht,         //!< Half transfer event.
    tc,         //!< Transfer complete event.
    err,        //!< Error event.
};

//! Defines async xfer types.
enum class async_type
{
    deferred,   //!< Xfer going to be deferred until user asks.
    immediate,  //!< Xfer will be executed as soon as possible.
};

//!
//! \brief Event handler type.
//! User can provide a function object in order to handle events from a bus.
//! \param[in] ch    Channel where event occurred.
//! \param[in] type  Type of the event.
//! \param[in] total Bytes transferred trough given channel
//!                  during current xfer.
//! \sa generic_bus::xfer()
//!
using bus_handler = std::function<void(bus_channel ch, bus_event type, size_t total)>;

//!
//! \brief The dummy bus class.
//! Provided just as an API example of platform-level bus.
//!
class dummy_platform_bus
{
public:
    //!
    //! \brief Lazy initialization.
    //! \return Status of operation.
    //!
    static err init()
    { return err::nosys; }

    //!
    //! \brief Sets rx buffer with given size.
    //! \param[in,out]  rx      Buffer to write data to. Optional.
    //! \param[in]      size    Size
    //!
    static void set_rx(uint8_t *rx, size_t size)
    { (void) rx; (void) size; }

    //!
    //! \brief Sets rx buffer made-up from sequence of similar bytes.
    //! \param[in] size         Size of sequence
    //! \param[in] fill_byte    Byte to fill a sequence. Optional.
    //!
    static void set_tx(size_t size, uint8_t fill_byte = 0xff)
    { (void) size; (void) fill_byte; }

    //!
    //! \brief Sets tx buffer with given size.
    //! \param[in] tx   Buffer to transmit. Optional.
    //! \param[in] size Buffer size.
    //!
    static void set_tx(const uint8_t *tx, size_t size)
    { (void) tx; (void) size; }

    //!
    //! \brief Sets event handler.
    //! Handler will be used by the bus, until reset_handler() will be called.
    //! \param[in] handler Handler itself.
    //!
    static void set_handler(const bus_handler &handler)
    { (void) handler; }

    //!
    //! \brief Reset xfer buffers.
    //! Buffers that were set by \sa set_tx() and \sa set_rx()
    //! will be no longer used after this call.
    //!
    static void reset_buffers()
    { return; }

    //!
    //! \brief Resets previously set handler.
    //!
    static void reset_handler()
    { return; }

    //!
    //! \brief Executes xfer, using buffers previously set.
    //! When it will be done, handler will be invoked.
    //! \return Status of operation.
    //!
    static err do_xfer()
    { return err::nosys; }

    //!
    //! \brief Cancels xfer.
    //! After this call no xfer will occur.
    //! \return Status of operation.
    //!
    static err cancel_xfer()
    { return err::nosys; }
};

} // namespace ecl


#endif // PLATFORM_COMMON_BUS_
