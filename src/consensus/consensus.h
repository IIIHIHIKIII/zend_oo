// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_CONSENSUS_H
#define BITCOIN_CONSENSUS_CONSENSUS_H

/** legacy block versions
 *--------------------------
 * this is the most recent block version before sidechain fork. Blocks mined up to such fork
 * will still have this version */
static const int32_t BLOCK_VERSION_BEFORE_SC  = 0x20000000;

/** old legacy fork */
static const int32_t BLOCK_VERSION_ORIGINAL   = 0x4;

/** new block version valid from sidechain fork on 
 * We choose this value since:
 * 1. it is a number < 4, this is to enforce that before the sidechain fork and deprecation
 *    date, any block with that value is rejected by both legacy and update node
 * 2. it is the larger number < 4, this is to update the MIN_BLOCK_VERSION macro below, which is
 *    tested in the code for checking block validity  */
static const int32_t BLOCK_VERSION_SC_SUPPORT = 0x3;

/** The minimum allowed block version (network rule) */
static const int32_t MIN_BLOCK_VERSION = BLOCK_VERSION_SC_SUPPORT;

/** The minimum allowed transaction version (network rule) */
static const int32_t MIN_OLD_TX_VERSION = 1;
/** The maximum allowed size for a serialized block, in bytes (network rule) */
static const unsigned int MAX_BLOCK_SIZE = 2000000;
/** The maximum allowed number of signature check operations in a block (network rule) */
static const unsigned int MAX_BLOCK_SIGOPS = 20000;
/** The maximum size of a transaction (network rule) */
static const unsigned int MAX_TX_SIZE = 100000;
/** The minimum theoretical possible size of a consistent tx*/
static const unsigned int MIN_TX_SIZE = 61;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY = 100;

/** Flags for LockTime() */
enum {
    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

/** Used as the flags parameter to CheckFinalTx() in non-consensus code */
static const unsigned int STANDARD_LOCKTIME_VERIFY_FLAGS = LOCKTIME_MEDIAN_TIME_PAST;

#endif // BITCOIN_CONSENSUS_CONSENSUS_H
