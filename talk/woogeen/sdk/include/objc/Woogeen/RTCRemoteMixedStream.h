/*
 * Copyright © 2016 Intel Corporation. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WOOGEEN_CONFERENCE_OBJC_RTCREMOTEMIXEDSTREAM_H_
#define WOOGEEN_CONFERENCE_OBJC_RTCREMOTEMIXEDSTREAM_H_

#import "Woogeen/RTCRemoteStream.h"
#import "Woogeen/RTCRemoteMixedStreamObserver.h"

NS_ASSUME_NONNULL_BEGIN

/// This class represent a mixed remote stream.
RTC_EXPORT
@interface RTCRemoteMixedStream : RTCRemoteStream

-(NSArray*)supportedVideoFormats;
/**
  @brief Add an observer for RTCRemoteMixedStream.
*/
- (void)addObserver:(id<RTCRemoteMixedStreamObserver>)observer;

/**
  @brief A property of mixed streams which distinguishes them from other mixed
  streams a conference room provides.
  @detail A conference room, since Intel CS for WebRTC v3.4 and later, has been
  extended to support multiple presentations of the mixed audio and video for
  variant purposes. For example, in remote education scenario, the teacher and
  students may subscribe different mixed streams with view of 'teacher' and
  'student' respectively in the same class conference room. It is also the label
  of a mixed stream indicating its peculiarity with a meaningful string-typed
  value, which must be unique within a room.
*/
@property(readonly, strong) NSString* viewport;

@end

#endif // WOOGEEN_CONFERENCE_OBJC_RTCREMOTEMIXEDSTREAM_H_

NS_ASSUME_NONNULL_END
