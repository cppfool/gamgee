#ifndef __gamgee__sam_header__
#define __gamgee__sam_header__

#include "htslib/sam.h"

#include <memory>
#include <string>

namespace gamgee {

/**
 * @brief Utility class to hold the header of a sam file
 */
class SamHeader {
 public:
  explicit SamHeader() = default;                               ///< @brief initializes a null SamHeader @warning if you need to create a SamHeader from scratch, use the builder instead
  explicit SamHeader(const std::shared_ptr<bam_hdr_t>& header); ///< @brief creates a SamHeader given htslib object. @note used by all iterators
  SamHeader(const SamHeader& other);                            ///< @brief makes a deep copy of a SamHeader. Shared pointers maintain state to all other associated objects correctly.
  SamHeader(SamHeader&& other) noexcept;                        ///< @brief moves SamHeader accordingly. Shared pointers maintain state to all other associated objects correctly.
  SamHeader& operator=(const SamHeader& other);                 ///< @brief deep copy assignment of a SamHeader. Shared pointers maintain state to all other associated objects correctly.
  SamHeader& operator=(SamHeader&& other) noexcept;             ///< @brief move assignment of a SamHeader. Shared pointers maintain state to all other associated objects correctly.
  uint32_t sequence_length(const std::string& sequence_name);   ///< @brief Returns the length of the given sequence as stored in the @SQ tag in the BAM header.
  uint32_t sequence_length(const uint32_t sequence_index);      ///< @brief Returns the length of the given sequence as stored in the @SQ tag in the BAM header.
  std::string sequence_name(const uint32_t sequence_index);	    ///< @brief Returns the sequence name for the sequence with the given zero-based index

 private:
  std::shared_ptr<bam_hdr_t> m_header;

  friend class SamWriter;
};

}
#endif 