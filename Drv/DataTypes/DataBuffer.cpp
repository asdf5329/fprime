#include <Drv/DataTypes/DataBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Drv {
        
    DataBuffer::DataBuffer(const U8 *args, NATIVE_UINT_TYPE size) {
        Fw::SerializeStatus stat = Fw::SerializeBufferBase::setBuff(args,size);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == stat,static_cast<NATIVE_INT_TYPE>(stat));
    }
    
    DataBuffer::DataBuffer() {
    }

    DataBuffer::~DataBuffer() {
    }

    DataBuffer::DataBuffer(const DataBuffer& other) : Fw::SerializeBufferBase() {
        Fw::SerializeStatus stat = Fw::SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        FW_ASSERT(Fw::FW_SERIALIZE_OK == stat,static_cast<NATIVE_INT_TYPE>(stat));
    }

    const DataBuffer& DataBuffer::operator=(const DataBuffer& other) {
        Fw::SerializeStatus stat = Fw::SerializeBufferBase::setBuff(other.m_data,other.getBuffLength());
        FW_ASSERT(Fw::FW_SERIALIZE_OK == stat,static_cast<NATIVE_INT_TYPE>(stat));
        return *this;
    }

    NATIVE_UINT_TYPE DataBuffer::getBuffCapacity(void) const {
        return sizeof(this->m_data);
    }

    const U8* DataBuffer::getBuffAddr(void) const {
        return this->m_data;
    }

    U8* DataBuffer::getBuffAddr(void) {
        return this->m_data;
    }

}
