/*
 * This file was generated with gl3w_gen.py, part of gl3w
 * (hosted at https://github.com/skaslev/gl3w)
 *
 * This is free and unencumbered software released into the
 * public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell,
 * or distribute this software, either in source code form or as
 * a compiled binary, for any purpose, commercial or
 * non-commercial, and by any means.
 *
 * In jurisdictions that recognize copyright laws, the author or
 * authors of this software dedicate any and all copyright
 * interest in the software to the public domain. We make this
 * dedication for the benefit of the public at large and to the
 * detriment of our heirs and successors. We intend this
 * dedication to be an overt act of relinquishment in perpetuity
 * of all present and future rights to this software under
 * copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __gl3w_h_
#define __gl3w_h_

#include <GL/glcorearb.h>

#define _COSMO_SOURCE
#include "libc/dce.h"

#ifndef GL3W_API
#define GL3W_API
#endif

#ifndef __gl_h_
#define __gl_h_
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define GL3W_OK 0
#define GL3W_ERROR_INIT -1
#define GL3W_ERROR_LIBRARY_OPEN -2
#define GL3W_ERROR_OPENGL_VERSION -3

/* gl3w api */
GL3W_API void GL3W_init(void);

/* gl3w internal state */
union GL3WProcs {
    void *ptr[659];
    struct {
        GLboolean (*glIsBuffer)(GLuint buffer);
        GLboolean (*glIsEnabled)(GLenum cap);
        GLboolean (*glIsEnabledi)(GLenum target, GLuint index);
        GLboolean (*glIsFramebuffer)(GLuint framebuffer);
        GLboolean (*glIsProgram)(GLuint program);
        GLboolean (*glIsProgramPipeline)(GLuint pipeline);
        GLboolean (*glIsQuery)(GLuint id);
        GLboolean (*glIsRenderbuffer)(GLuint renderbuffer);
        GLboolean (*glIsSampler)(GLuint sampler);
        GLboolean (*glIsShader)(GLuint shader);
        GLboolean (*glIsSync)(GLsync sync);
        GLboolean (*glIsTexture)(GLuint texture);
        GLboolean (*glIsTransformFeedback)(GLuint id);
        GLboolean (*glIsVertexArray)(GLuint array);
        GLboolean (*glUnmapBuffer)(GLenum target);
        GLboolean (*glUnmapNamedBuffer)(GLuint buffer);
        GLenum (*glCheckFramebufferStatus)(GLenum target);
        GLenum (*glCheckNamedFramebufferStatus)(
            GLuint framebuffer,
            GLenum target);
        GLenum (*glClientWaitSync)(
            GLsync sync,
            GLbitfield flags,
            GLuint64 timeout);
        GLenum (*glGetError)(void);
        GLenum (*glGetGraphicsResetStatus)(void);
        GLint (*glGetAttribLocation)(
            GLuint program,
            const GLchar *name);
        GLint (*glGetFragDataIndex)(
            GLuint program,
            const GLchar *name);
        GLint (*glGetFragDataLocation)(
            GLuint program,
            const GLchar *name);
        GLint (*glGetProgramResourceLocation)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLint (*glGetProgramResourceLocationIndex)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLint (*glGetSubroutineUniformLocation)(
            GLuint program,
            GLenum shadertype,
            const GLchar *name);
        GLint (*glGetUniformLocation)(
            GLuint program,
            const GLchar *name);
        GLsync (
            *glFenceSync)(GLenum condition, GLbitfield flags);
        GLuint (*glCreateProgram)(void);
        GLuint (*glCreateShader)(GLenum type);
        GLuint (*glCreateShaderProgramv)(
            GLenum type,
            GLsizei count,
            const GLchar *const *strings);
        GLuint (*glGetDebugMessageLog)(
            GLuint count,
            GLsizei bufSize,
            GLenum *sources,
            GLenum *types,
            GLuint *ids,
            GLenum *severities,
            GLsizei *lengths,
            GLchar *messageLog);
        GLuint (*glGetProgramResourceIndex)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLuint (*glGetSubroutineIndex)(
            GLuint program,
            GLenum shadertype,
            const GLchar *name);
        GLuint (*glGetUniformBlockIndex)(
            GLuint program,
            const GLchar *uniformBlockName);
        const GLubyte *(*glGetString)(GLenum name);
        const GLubyte *(
            *glGetStringi)(GLenum name, GLuint index);
        void (*glActiveShaderProgram)(
            GLuint pipeline,
            GLuint program);
        void (*glActiveTexture)(GLenum texture);
        void (*glAttachShader)(GLuint program, GLuint shader);
        void (*glBeginConditionalRender)(GLuint id, GLenum mode);
        void (*glBeginQuery)(GLenum target, GLuint id);
        void (*glBeginQueryIndexed)(
            GLenum target,
            GLuint index,
            GLuint id);
        void (*glBeginTransformFeedback)(GLenum primitiveMode);
        void (*glBindAttribLocation)(
            GLuint program,
            GLuint index,
            const GLchar *name);
        void (*glBindBuffer)(GLenum target, GLuint buffer);
        void (*glBindBufferBase)(
            GLenum target,
            GLuint index,
            GLuint buffer);
        void (*glBindBufferRange)(
            GLenum target,
            GLuint index,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*glBindBuffersBase)(
            GLenum target,
            GLuint first,
            GLsizei count,
            const GLuint *buffers);
        void (*glBindBuffersRange)(
            GLenum target,
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizeiptr *sizes);
        void (*glBindFragDataLocation)(
            GLuint program,
            GLuint color,
            const GLchar *name);
        void (*glBindFragDataLocationIndexed)(
            GLuint program,
            GLuint colorNumber,
            GLuint index,
            const GLchar *name);
        void (*glBindFramebuffer)(
            GLenum target,
            GLuint framebuffer);
        void (*glBindImageTexture)(
            GLuint unit,
            GLuint texture,
            GLint level,
            GLboolean layered,
            GLint layer,
            GLenum access,
            GLenum format);
        void (*glBindImageTextures)(
            GLuint first,
            GLsizei count,
            const GLuint *textures);
        void (*glBindProgramPipeline)(GLuint pipeline);
        void (*glBindRenderbuffer)(
            GLenum target,
            GLuint renderbuffer);
        void (*glBindSampler)(GLuint unit, GLuint sampler);
        void (*glBindSamplers)(
            GLuint first,
            GLsizei count,
            const GLuint *samplers);
        void (*glBindTexture)(GLenum target, GLuint texture);
        void (*glBindTextureUnit)(GLuint unit, GLuint texture);
        void (*glBindTextures)(
            GLuint first,
            GLsizei count,
            const GLuint *textures);
        void (
            *glBindTransformFeedback)(GLenum target, GLuint id);
        void (*glBindVertexArray)(GLuint array);
        void (*glBindVertexBuffer)(
            GLuint bindingindex,
            GLuint buffer,
            GLintptr offset,
            GLsizei stride);
        void (*glBindVertexBuffers)(
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizei *strides);
        void (*glBlendColor)(
            GLfloat red,
            GLfloat green,
            GLfloat blue,
            GLfloat alpha);
        void (*glBlendEquation)(GLenum mode);
        void (*glBlendEquationSeparate)(
            GLenum modeRGB,
            GLenum modeAlpha);
        void (*glBlendEquationSeparatei)(
            GLuint buf,
            GLenum modeRGB,
            GLenum modeAlpha);
        void (*glBlendEquationi)(GLuint buf, GLenum mode);
        void (*glBlendFunc)(GLenum sfactor, GLenum dfactor);
        void (*glBlendFuncSeparate)(
            GLenum sfactorRGB,
            GLenum dfactorRGB,
            GLenum sfactorAlpha,
            GLenum dfactorAlpha);
        void (*glBlendFuncSeparatei)(
            GLuint buf,
            GLenum srcRGB,
            GLenum dstRGB,
            GLenum srcAlpha,
            GLenum dstAlpha);
        void (*glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
        void (*glBlitFramebuffer)(
            GLint srcX0,
            GLint srcY0,
            GLint srcX1,
            GLint srcY1,
            GLint dstX0,
            GLint dstY0,
            GLint dstX1,
            GLint dstY1,
            GLbitfield mask,
            GLenum filter);
        void (*glBlitNamedFramebuffer)(
            GLuint readFramebuffer,
            GLuint drawFramebuffer,
            GLint srcX0,
            GLint srcY0,
            GLint srcX1,
            GLint srcY1,
            GLint dstX0,
            GLint dstY0,
            GLint dstX1,
            GLint dstY1,
            GLbitfield mask,
            GLenum filter);
        void (*glBufferData)(
            GLenum target,
            GLsizeiptr size,
            const void *data,
            GLenum usage);
        void (*glBufferStorage)(
            GLenum target,
            GLsizeiptr size,
            const void *data,
            GLbitfield flags);
        void (*glBufferSubData)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr size,
            const void *data);
        void (*glClampColor)(GLenum target, GLenum clamp);
        void (*glClear)(GLbitfield mask);
        void (*glClearBufferData)(
            GLenum target,
            GLenum internalformat,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClearBufferSubData)(
            GLenum target,
            GLenum internalformat,
            GLintptr offset,
            GLsizeiptr size,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClearBufferfi)(
            GLenum buffer,
            GLint drawbuffer,
            GLfloat depth,
            GLint stencil);
        void (*glClearBufferfv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLfloat *value);
        void (*glClearBufferiv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLint *value);
        void (*glClearBufferuiv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLuint *value);
        void (*glClearColor)(
            GLfloat red,
            GLfloat green,
            GLfloat blue,
            GLfloat alpha);
        void (*glClearDepth)(GLdouble depth);
        void (*glClearDepthf)(GLfloat d);
        void (*glClearNamedBufferData)(
            GLuint buffer,
            GLenum internalformat,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClearNamedBufferSubData)(
            GLuint buffer,
            GLenum internalformat,
            GLintptr offset,
            GLsizeiptr size,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClearNamedFramebufferfi)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            GLfloat depth,
            GLint stencil);
        void (*glClearNamedFramebufferfv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLfloat *value);
        void (*glClearNamedFramebufferiv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLint *value);
        void (*glClearNamedFramebufferuiv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLuint *value);
        void (*glClearStencil)(GLint s);
        void (*glClearTexImage)(
            GLuint texture,
            GLint level,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClearTexSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *data);
        void (*glClipControl)(GLenum origin, GLenum depth);
        void (*glColorMask)(
            GLboolean red,
            GLboolean green,
            GLboolean blue,
            GLboolean alpha);
        void (*glColorMaski)(
            GLuint index,
            GLboolean r,
            GLboolean g,
            GLboolean b,
            GLboolean a);
        void (*glCompileShader)(GLuint shader);
        void (*glCompressedTexImage1D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTexImage2D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTexImage3D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCompressedTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*glCopyBufferSubData)(
            GLenum readTarget,
            GLenum writeTarget,
            GLintptr readOffset,
            GLintptr writeOffset,
            GLsizeiptr size);
        void (*glCopyImageSubData)(
            GLuint srcName,
            GLenum srcTarget,
            GLint srcLevel,
            GLint srcX,
            GLint srcY,
            GLint srcZ,
            GLuint dstName,
            GLenum dstTarget,
            GLint dstLevel,
            GLint dstX,
            GLint dstY,
            GLint dstZ,
            GLsizei srcWidth,
            GLsizei srcHeight,
            GLsizei srcDepth);
        void (*glCopyNamedBufferSubData)(
            GLuint readBuffer,
            GLuint writeBuffer,
            GLintptr readOffset,
            GLintptr writeOffset,
            GLsizeiptr size);
        void (*glCopyTexImage1D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLint x,
            GLint y,
            GLsizei width,
            GLint border);
        void (*glCopyTexImage2D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLint border);
        void (*glCopyTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint x,
            GLint y,
            GLsizei width);
        void (*glCopyTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glCopyTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glCopyTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint x,
            GLint y,
            GLsizei width);
        void (*glCopyTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glCopyTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glCreateBuffers)(GLsizei n, GLuint *buffers);
        void (*glCreateFramebuffers)(
            GLsizei n,
            GLuint *framebuffers);
        void (*glCreateProgramPipelines)(
            GLsizei n,
            GLuint *pipelines);
        void (*glCreateQueries)(
            GLenum target,
            GLsizei n,
            GLuint *ids);
        void (*glCreateRenderbuffers)(
            GLsizei n,
            GLuint *renderbuffers);
        void (*glCreateSamplers)(GLsizei n, GLuint *samplers);
        void (*glCreateTextures)(
            GLenum target,
            GLsizei n,
            GLuint *textures);
        void (
            *glCreateTransformFeedbacks)(GLsizei n, GLuint *ids);
        void (*glCreateVertexArrays)(GLsizei n, GLuint *arrays);
        void (*glCullFace)(GLenum mode);
        void (*glDebugMessageCallback)(
            GLDEBUGPROC callback,
            const void *userParam);
        void (*glDebugMessageControl)(
            GLenum source,
            GLenum type,
            GLenum severity,
            GLsizei count,
            const GLuint *ids,
            GLboolean enabled);
        void (*glDebugMessageInsert)(
            GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar *buf);
        void (
            *glDeleteBuffers)(GLsizei n, const GLuint *buffers);
        void (*glDeleteFramebuffers)(
            GLsizei n,
            const GLuint *framebuffers);
        void (*glDeleteProgram)(GLuint program);
        void (*glDeleteProgramPipelines)(
            GLsizei n,
            const GLuint *pipelines);
        void (*glDeleteQueries)(GLsizei n, const GLuint *ids);
        void (*glDeleteRenderbuffers)(
            GLsizei n,
            const GLuint *renderbuffers);
        void (*glDeleteSamplers)(
            GLsizei count,
            const GLuint *samplers);
        void (*glDeleteShader)(GLuint shader);
        void (*glDeleteSync)(GLsync sync);
        void (*glDeleteTextures)(
            GLsizei n,
            const GLuint *textures);
        void (*glDeleteTransformFeedbacks)(
            GLsizei n,
            const GLuint *ids);
        void (*glDeleteVertexArrays)(
            GLsizei n,
            const GLuint *arrays);
        void (*glDepthFunc)(GLenum func);
        void (*glDepthMask)(GLboolean flag);
        void (*glDepthRange)(GLdouble n, GLdouble f);
        void (*glDepthRangeArrayv)(
            GLuint first,
            GLsizei count,
            const GLdouble *v);
        void (*glDepthRangeIndexed)(
            GLuint index,
            GLdouble n,
            GLdouble f);
        void (*glDepthRangef)(GLfloat n, GLfloat f);
        void (*glDetachShader)(GLuint program, GLuint shader);
        void (*glDisable)(GLenum cap);
        void (*glDisableVertexArrayAttrib)(
            GLuint vaobj,
            GLuint index);
        void (*glDisableVertexAttribArray)(GLuint index);
        void (*glDisablei)(GLenum target, GLuint index);
        void (*glDispatchCompute)(
            GLuint num_groups_x,
            GLuint num_groups_y,
            GLuint num_groups_z);
        void (*glDispatchComputeIndirect)(GLintptr indirect);
        void (*glDrawArrays)(
            GLenum mode,
            GLint first,
            GLsizei count);
        void (*glDrawArraysIndirect)(
            GLenum mode,
            const void *indirect);
        void (*glDrawArraysInstanced)(
            GLenum mode,
            GLint first,
            GLsizei count,
            GLsizei instancecount);
        void (*glDrawArraysInstancedBaseInstance)(
            GLenum mode,
            GLint first,
            GLsizei count,
            GLsizei instancecount,
            GLuint baseinstance);
        void (*glDrawBuffer)(GLenum buf);
        void (*glDrawBuffers)(GLsizei n, const GLenum *bufs);
        void (*glDrawElements)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices);
        void (*glDrawElementsBaseVertex)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLint basevertex);
        void (*glDrawElementsIndirect)(
            GLenum mode,
            GLenum type,
            const void *indirect);
        void (*glDrawElementsInstanced)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount);
        void (*glDrawElementsInstancedBaseInstance)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLuint baseinstance);
        void (*glDrawElementsInstancedBaseVertex)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLint basevertex);
        void (*glDrawElementsInstancedBaseVertexBaseInstance)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLint basevertex,
            GLuint baseinstance);
        void (*glDrawRangeElements)(
            GLenum mode,
            GLuint start,
            GLuint end,
            GLsizei count,
            GLenum type,
            const void *indices);
        void (*glDrawRangeElementsBaseVertex)(
            GLenum mode,
            GLuint start,
            GLuint end,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLint basevertex);
        void (*glDrawTransformFeedback)(GLenum mode, GLuint id);
        void (*glDrawTransformFeedbackInstanced)(
            GLenum mode,
            GLuint id,
            GLsizei instancecount);
        void (*glDrawTransformFeedbackStream)(
            GLenum mode,
            GLuint id,
            GLuint stream);
        void (*glDrawTransformFeedbackStreamInstanced)(
            GLenum mode,
            GLuint id,
            GLuint stream,
            GLsizei instancecount);
        void (*glEnable)(GLenum cap);
        void (*glEnableVertexArrayAttrib)(
            GLuint vaobj,
            GLuint index);
        void (*glEnableVertexAttribArray)(GLuint index);
        void (*glEnablei)(GLenum target, GLuint index);
        void (*glEndConditionalRender)(void);
        void (*glEndQuery)(GLenum target);
        void (*glEndQueryIndexed)(GLenum target, GLuint index);
        void (*glEndTransformFeedback)(void);
        void (*glFinish)(void);
        void (*glFlush)(void);
        void (*glFlushMappedBufferRange)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr length);
        void (*glFlushMappedNamedBufferRange)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length);
        void (*glFramebufferParameteri)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*glFramebufferParameteriMESA)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*glFramebufferRenderbuffer)(
            GLenum target,
            GLenum attachment,
            GLenum renderbuffertarget,
            GLuint renderbuffer);
        void (*glFramebufferTexture)(
            GLenum target,
            GLenum attachment,
            GLuint texture,
            GLint level);
        void (*glFramebufferTexture1D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level);
        void (*glFramebufferTexture2D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level);
        void (*glFramebufferTexture3D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level,
            GLint zoffset);
        void (*glFramebufferTextureLayer)(
            GLenum target,
            GLenum attachment,
            GLuint texture,
            GLint level,
            GLint layer);
        void (*glFrontFace)(GLenum mode);
        void (*glGenBuffers)(GLsizei n, GLuint *buffers);
        void (
            *glGenFramebuffers)(GLsizei n, GLuint *framebuffers);
        void (*glGenProgramPipelines)(
            GLsizei n,
            GLuint *pipelines);
        void (*glGenQueries)(GLsizei n, GLuint *ids);
        void (*glGenRenderbuffers)(
            GLsizei n,
            GLuint *renderbuffers);
        void (*glGenSamplers)(GLsizei count, GLuint *samplers);
        void (*glGenTextures)(GLsizei n, GLuint *textures);
        void (*glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
        void (*glGenVertexArrays)(GLsizei n, GLuint *arrays);
        void (*glGenerateMipmap)(GLenum target);
        void (*glGenerateTextureMipmap)(GLuint texture);
        void (*glGetActiveAtomicCounterBufferiv)(
            GLuint program,
            GLuint bufferIndex,
            GLenum pname,
            GLint *params);
        void (*glGetActiveAttrib)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLint *size,
            GLenum *type,
            GLchar *name);
        void (*glGetActiveSubroutineName)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*glGetActiveSubroutineUniformName)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*glGetActiveSubroutineUniformiv)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLenum pname,
            GLint *values);
        void (*glGetActiveUniform)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLint *size,
            GLenum *type,
            GLchar *name);
        void (*glGetActiveUniformBlockName)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *uniformBlockName);
        void (*glGetActiveUniformBlockiv)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLenum pname,
            GLint *params);
        void (*glGetActiveUniformName)(
            GLuint program,
            GLuint uniformIndex,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *uniformName);
        void (*glGetActiveUniformsiv)(
            GLuint program,
            GLsizei uniformCount,
            const GLuint *uniformIndices,
            GLenum pname,
            GLint *params);
        void (*glGetAttachedShaders)(
            GLuint program,
            GLsizei maxCount,
            GLsizei *count,
            GLuint *shaders);
        void (*glGetBooleani_v)(
            GLenum target,
            GLuint index,
            GLboolean *data);
        void (*glGetBooleanv)(GLenum pname, GLboolean *data);
        void (*glGetBufferParameteri64v)(
            GLenum target,
            GLenum pname,
            GLint64 *params);
        void (*glGetBufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetBufferPointerv)(
            GLenum target,
            GLenum pname,
            void **params);
        void (*glGetBufferSubData)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr size,
            void *data);
        void (*glGetCompressedTexImage)(
            GLenum target,
            GLint level,
            void *img);
        void (*glGetCompressedTextureImage)(
            GLuint texture,
            GLint level,
            GLsizei bufSize,
            void *pixels);
        void (*glGetCompressedTextureSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLsizei bufSize,
            void *pixels);
        void (*glGetDoublei_v)(
            GLenum target,
            GLuint index,
            GLdouble *data);
        void (*glGetDoublev)(GLenum pname, GLdouble *data);
        void (*glGetFloati_v)(
            GLenum target,
            GLuint index,
            GLfloat *data);
        void (*glGetFloatv)(GLenum pname, GLfloat *data);
        void (*glGetFramebufferAttachmentParameteriv)(
            GLenum target,
            GLenum attachment,
            GLenum pname,
            GLint *params);
        void (*glGetFramebufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetFramebufferParameterivMESA)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetInteger64i_v)(
            GLenum target,
            GLuint index,
            GLint64 *data);
        void (*glGetInteger64v)(GLenum pname, GLint64 *data);
        void (*glGetIntegeri_v)(
            GLenum target,
            GLuint index,
            GLint *data);
        void (*glGetIntegerv)(GLenum pname, GLint *data);
        void (*glGetInternalformati64v)(
            GLenum target,
            GLenum internalformat,
            GLenum pname,
            GLsizei count,
            GLint64 *params);
        void (*glGetInternalformativ)(
            GLenum target,
            GLenum internalformat,
            GLenum pname,
            GLsizei count,
            GLint *params);
        void (*glGetMultisamplefv)(
            GLenum pname,
            GLuint index,
            GLfloat *val);
        void (*glGetNamedBufferParameteri64v)(
            GLuint buffer,
            GLenum pname,
            GLint64 *params);
        void (*glGetNamedBufferParameteriv)(
            GLuint buffer,
            GLenum pname,
            GLint *params);
        void (*glGetNamedBufferPointerv)(
            GLuint buffer,
            GLenum pname,
            void **params);
        void (*glGetNamedBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size,
            void *data);
        void (*glGetNamedFramebufferAttachmentParameteriv)(
            GLuint framebuffer,
            GLenum attachment,
            GLenum pname,
            GLint *params);
        void (*glGetNamedFramebufferParameteriv)(
            GLuint framebuffer,
            GLenum pname,
            GLint *param);
        void (*glGetNamedRenderbufferParameteriv)(
            GLuint renderbuffer,
            GLenum pname,
            GLint *params);
        void (*glGetObjectLabel)(
            GLenum identifier,
            GLuint name,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *label);
        void (*glGetObjectPtrLabel)(
            const void *ptr,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *label);
        void (*glGetPointerv)(GLenum pname, void **params);
        void (*glGetProgramBinary)(
            GLuint program,
            GLsizei bufSize,
            GLsizei *length,
            GLenum *binaryFormat,
            void *binary);
        void (*glGetProgramInfoLog)(
            GLuint program,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*glGetProgramInterfaceiv)(
            GLuint program,
            GLenum programInterface,
            GLenum pname,
            GLint *params);
        void (*glGetProgramPipelineInfoLog)(
            GLuint pipeline,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*glGetProgramPipelineiv)(
            GLuint pipeline,
            GLenum pname,
            GLint *params);
        void (*glGetProgramResourceName)(
            GLuint program,
            GLenum programInterface,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*glGetProgramResourceiv)(
            GLuint program,
            GLenum programInterface,
            GLuint index,
            GLsizei propCount,
            const GLenum *props,
            GLsizei count,
            GLsizei *length,
            GLint *params);
        void (*glGetProgramStageiv)(
            GLuint program,
            GLenum shadertype,
            GLenum pname,
            GLint *values);
        void (*glGetProgramiv)(
            GLuint program,
            GLenum pname,
            GLint *params);
        void (*glGetQueryBufferObjecti64v)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*glGetQueryBufferObjectiv)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*glGetQueryBufferObjectui64v)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*glGetQueryBufferObjectuiv)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*glGetQueryIndexediv)(
            GLenum target,
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*glGetQueryObjecti64v)(
            GLuint id,
            GLenum pname,
            GLint64 *params);
        void (*glGetQueryObjectiv)(
            GLuint id,
            GLenum pname,
            GLint *params);
        void (*glGetQueryObjectui64v)(
            GLuint id,
            GLenum pname,
            GLuint64 *params);
        void (*glGetQueryObjectuiv)(
            GLuint id,
            GLenum pname,
            GLuint *params);
        void (*glGetQueryiv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetRenderbufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetSamplerParameterIiv)(
            GLuint sampler,
            GLenum pname,
            GLint *params);
        void (*glGetSamplerParameterIuiv)(
            GLuint sampler,
            GLenum pname,
            GLuint *params);
        void (*glGetSamplerParameterfv)(
            GLuint sampler,
            GLenum pname,
            GLfloat *params);
        void (*glGetSamplerParameteriv)(
            GLuint sampler,
            GLenum pname,
            GLint *params);
        void (*glGetShaderInfoLog)(
            GLuint shader,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*glGetShaderPrecisionFormat)(
            GLenum shadertype,
            GLenum precisiontype,
            GLint *range,
            GLint *precision);
        void (*glGetShaderSource)(
            GLuint shader,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *source);
        void (*glGetShaderiv)(
            GLuint shader,
            GLenum pname,
            GLint *params);
        void (*glGetSynciv)(
            GLsync sync,
            GLenum pname,
            GLsizei count,
            GLsizei *length,
            GLint *values);
        void (*glGetTexImage)(
            GLenum target,
            GLint level,
            GLenum format,
            GLenum type,
            void *pixels);
        void (*glGetTexLevelParameterfv)(
            GLenum target,
            GLint level,
            GLenum pname,
            GLfloat *params);
        void (*glGetTexLevelParameteriv)(
            GLenum target,
            GLint level,
            GLenum pname,
            GLint *params);
        void (*glGetTexParameterIiv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetTexParameterIuiv)(
            GLenum target,
            GLenum pname,
            GLuint *params);
        void (*glGetTexParameterfv)(
            GLenum target,
            GLenum pname,
            GLfloat *params);
        void (*glGetTexParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*glGetTextureImage)(
            GLuint texture,
            GLint level,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*glGetTextureLevelParameterfv)(
            GLuint texture,
            GLint level,
            GLenum pname,
            GLfloat *params);
        void (*glGetTextureLevelParameteriv)(
            GLuint texture,
            GLint level,
            GLenum pname,
            GLint *params);
        void (*glGetTextureParameterIiv)(
            GLuint texture,
            GLenum pname,
            GLint *params);
        void (*glGetTextureParameterIuiv)(
            GLuint texture,
            GLenum pname,
            GLuint *params);
        void (*glGetTextureParameterfv)(
            GLuint texture,
            GLenum pname,
            GLfloat *params);
        void (*glGetTextureParameteriv)(
            GLuint texture,
            GLenum pname,
            GLint *params);
        void (*glGetTextureSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*glGetTransformFeedbackVarying)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLsizei *size,
            GLenum *type,
            GLchar *name);
        void (*glGetTransformFeedbacki64_v)(
            GLuint xfb,
            GLenum pname,
            GLuint index,
            GLint64 *param);
        void (*glGetTransformFeedbacki_v)(
            GLuint xfb,
            GLenum pname,
            GLuint index,
            GLint *param);
        void (*glGetTransformFeedbackiv)(
            GLuint xfb,
            GLenum pname,
            GLint *param);
        void (*glGetUniformIndices)(
            GLuint program,
            GLsizei uniformCount,
            const GLchar *const *uniformNames,
            GLuint *uniformIndices);
        void (*glGetUniformSubroutineuiv)(
            GLenum shadertype,
            GLint location,
            GLuint *params);
        void (*glGetUniformdv)(
            GLuint program,
            GLint location,
            GLdouble *params);
        void (*glGetUniformfv)(
            GLuint program,
            GLint location,
            GLfloat *params);
        void (*glGetUniformiv)(
            GLuint program,
            GLint location,
            GLint *params);
        void (*glGetUniformuiv)(
            GLuint program,
            GLint location,
            GLuint *params);
        void (*glGetVertexArrayIndexed64iv)(
            GLuint vaobj,
            GLuint index,
            GLenum pname,
            GLint64 *param);
        void (*glGetVertexArrayIndexediv)(
            GLuint vaobj,
            GLuint index,
            GLenum pname,
            GLint *param);
        void (*glGetVertexArrayiv)(
            GLuint vaobj,
            GLenum pname,
            GLint *param);
        void (*glGetVertexAttribIiv)(
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*glGetVertexAttribIuiv)(
            GLuint index,
            GLenum pname,
            GLuint *params);
        void (*glGetVertexAttribLdv)(
            GLuint index,
            GLenum pname,
            GLdouble *params);
        void (*glGetVertexAttribPointerv)(
            GLuint index,
            GLenum pname,
            void **pointer);
        void (*glGetVertexAttribdv)(
            GLuint index,
            GLenum pname,
            GLdouble *params);
        void (*glGetVertexAttribfv)(
            GLuint index,
            GLenum pname,
            GLfloat *params);
        void (*glGetVertexAttribiv)(
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*glGetnCompressedTexImage)(
            GLenum target,
            GLint lod,
            GLsizei bufSize,
            void *pixels);
        void (*glGetnTexImage)(
            GLenum target,
            GLint level,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*glGetnUniformdv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLdouble *params);
        void (*glGetnUniformfv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLfloat *params);
        void (*glGetnUniformiv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLint *params);
        void (*glGetnUniformuiv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLuint *params);
        void (*glHint)(GLenum target, GLenum mode);
        void (*glInvalidateBufferData)(GLuint buffer);
        void (*glInvalidateBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length);
        void (*glInvalidateFramebuffer)(
            GLenum target,
            GLsizei numAttachments,
            const GLenum *attachments);
        void (*glInvalidateNamedFramebufferData)(
            GLuint framebuffer,
            GLsizei numAttachments,
            const GLenum *attachments);
        void (*glInvalidateNamedFramebufferSubData)(
            GLuint framebuffer,
            GLsizei numAttachments,
            const GLenum *attachments,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glInvalidateSubFramebuffer)(
            GLenum target,
            GLsizei numAttachments,
            const GLenum *attachments,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (
            *glInvalidateTexImage)(GLuint texture, GLint level);
        void (*glInvalidateTexSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*glLineWidth)(GLfloat width);
        void (*glLinkProgram)(GLuint program);
        void (*glLogicOp)(GLenum opcode);
        void (*glMemoryBarrier)(GLbitfield barriers);
        void (*glMemoryBarrierByRegion)(GLbitfield barriers);
        void (*glMinSampleShading)(GLfloat value);
        void (*glMultiDrawArrays)(
            GLenum mode,
            const GLint *first,
            const GLsizei *count,
            GLsizei drawcount);
        void (*glMultiDrawArraysIndirect)(
            GLenum mode,
            const void *indirect,
            GLsizei drawcount,
            GLsizei stride);
        void (*glMultiDrawArraysIndirectCount)(
            GLenum mode,
            const void *indirect,
            GLintptr drawcount,
            GLsizei maxdrawcount,
            GLsizei stride);
        void (*glMultiDrawElements)(
            GLenum mode,
            const GLsizei *count,
            GLenum type,
            const void *const *indices,
            GLsizei drawcount);
        void (*glMultiDrawElementsBaseVertex)(
            GLenum mode,
            const GLsizei *count,
            GLenum type,
            const void *const *indices,
            GLsizei drawcount,
            const GLint *basevertex);
        void (*glMultiDrawElementsIndirect)(
            GLenum mode,
            GLenum type,
            const void *indirect,
            GLsizei drawcount,
            GLsizei stride);
        void (*glMultiDrawElementsIndirectCount)(
            GLenum mode,
            GLenum type,
            const void *indirect,
            GLintptr drawcount,
            GLsizei maxdrawcount,
            GLsizei stride);
        void (*glNamedBufferData)(
            GLuint buffer,
            GLsizeiptr size,
            const void *data,
            GLenum usage);
        void (*glNamedBufferStorage)(
            GLuint buffer,
            GLsizeiptr size,
            const void *data,
            GLbitfield flags);
        void (*glNamedBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size,
            const void *data);
        void (*glNamedFramebufferDrawBuffer)(
            GLuint framebuffer,
            GLenum buf);
        void (*glNamedFramebufferDrawBuffers)(
            GLuint framebuffer,
            GLsizei n,
            const GLenum *bufs);
        void (*glNamedFramebufferParameteri)(
            GLuint framebuffer,
            GLenum pname,
            GLint param);
        void (*glNamedFramebufferReadBuffer)(
            GLuint framebuffer,
            GLenum src);
        void (*glNamedFramebufferRenderbuffer)(
            GLuint framebuffer,
            GLenum attachment,
            GLenum renderbuffertarget,
            GLuint renderbuffer);
        void (*glNamedFramebufferTexture)(
            GLuint framebuffer,
            GLenum attachment,
            GLuint texture,
            GLint level);
        void (*glNamedFramebufferTextureLayer)(
            GLuint framebuffer,
            GLenum attachment,
            GLuint texture,
            GLint level,
            GLint layer);
        void (*glNamedRenderbufferStorage)(
            GLuint renderbuffer,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glNamedRenderbufferStorageMultisample)(
            GLuint renderbuffer,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glObjectLabel)(
            GLenum identifier,
            GLuint name,
            GLsizei length,
            const GLchar *label);
        void (*glObjectPtrLabel)(
            const void *ptr,
            GLsizei length,
            const GLchar *label);
        void (*glPatchParameterfv)(
            GLenum pname,
            const GLfloat *values);
        void (*glPatchParameteri)(GLenum pname, GLint value);
        void (*glPauseTransformFeedback)(void);
        void (*glPixelStoref)(GLenum pname, GLfloat param);
        void (*glPixelStorei)(GLenum pname, GLint param);
        void (*glPointParameterf)(GLenum pname, GLfloat param);
        void (*glPointParameterfv)(
            GLenum pname,
            const GLfloat *params);
        void (*glPointParameteri)(GLenum pname, GLint param);
        void (*glPointParameteriv)(
            GLenum pname,
            const GLint *params);
        void (*glPointSize)(GLfloat size);
        void (*glPolygonMode)(GLenum face, GLenum mode);
        void (*glPolygonOffset)(GLfloat factor, GLfloat units);
        void (*glPolygonOffsetClamp)(
            GLfloat factor,
            GLfloat units,
            GLfloat clamp);
        void (*glPopDebugGroup)(void);
        void (*glPrimitiveRestartIndex)(GLuint index);
        void (*glProgramBinary)(
            GLuint program,
            GLenum binaryFormat,
            const void *binary,
            GLsizei length);
        void (*glProgramParameteri)(
            GLuint program,
            GLenum pname,
            GLint value);
        void (*glProgramUniform1d)(
            GLuint program,
            GLint location,
            GLdouble v0);
        void (*glProgramUniform1dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glProgramUniform1f)(
            GLuint program,
            GLint location,
            GLfloat v0);
        void (*glProgramUniform1fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glProgramUniform1i)(
            GLuint program,
            GLint location,
            GLint v0);
        void (*glProgramUniform1iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glProgramUniform1ui)(
            GLuint program,
            GLint location,
            GLuint v0);
        void (*glProgramUniform1uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glProgramUniform2d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1);
        void (*glProgramUniform2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glProgramUniform2f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1);
        void (*glProgramUniform2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glProgramUniform2i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1);
        void (*glProgramUniform2iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glProgramUniform2ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1);
        void (*glProgramUniform2uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glProgramUniform3d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1,
            GLdouble v2);
        void (*glProgramUniform3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glProgramUniform3f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2);
        void (*glProgramUniform3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glProgramUniform3i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2);
        void (*glProgramUniform3iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glProgramUniform3ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2);
        void (*glProgramUniform3uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glProgramUniform4d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1,
            GLdouble v2,
            GLdouble v3);
        void (*glProgramUniform4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glProgramUniform4f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2,
            GLfloat v3);
        void (*glProgramUniform4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glProgramUniform4i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2,
            GLint v3);
        void (*glProgramUniform4iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glProgramUniform4ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2,
            GLuint v3);
        void (*glProgramUniform4uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glProgramUniformMatrix2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix2x3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix2x3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix2x4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix2x4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix3x2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix3x2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix3x4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix3x4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix4x2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix4x2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProgramUniformMatrix4x3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glProgramUniformMatrix4x3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glProvokingVertex)(GLenum mode);
        void (*glPushDebugGroup)(
            GLenum source,
            GLuint id,
            GLsizei length,
            const GLchar *message);
        void (*glQueryCounter)(GLuint id, GLenum target);
        void (*glReadBuffer)(GLenum src);
        void (*glReadPixels)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            void *pixels);
        void (*glReadnPixels)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *data);
        void (*glReleaseShaderCompiler)(void);
        void (*glRenderbufferStorage)(
            GLenum target,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glRenderbufferStorageMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glResumeTransformFeedback)(void);
        void (
            *glSampleCoverage)(GLfloat value, GLboolean invert);
        void (
            *glSampleMaski)(GLuint maskNumber, GLbitfield mask);
        void (*glSamplerParameterIiv)(
            GLuint sampler,
            GLenum pname,
            const GLint *param);
        void (*glSamplerParameterIuiv)(
            GLuint sampler,
            GLenum pname,
            const GLuint *param);
        void (*glSamplerParameterf)(
            GLuint sampler,
            GLenum pname,
            GLfloat param);
        void (*glSamplerParameterfv)(
            GLuint sampler,
            GLenum pname,
            const GLfloat *param);
        void (*glSamplerParameteri)(
            GLuint sampler,
            GLenum pname,
            GLint param);
        void (*glSamplerParameteriv)(
            GLuint sampler,
            GLenum pname,
            const GLint *param);
        void (*glScissor)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glScissorArrayv)(
            GLuint first,
            GLsizei count,
            const GLint *v);
        void (*glScissorIndexed)(
            GLuint index,
            GLint left,
            GLint bottom,
            GLsizei width,
            GLsizei height);
        void (*glScissorIndexedv)(GLuint index, const GLint *v);
        void (*glShaderBinary)(
            GLsizei count,
            const GLuint *shaders,
            GLenum binaryFormat,
            const void *binary,
            GLsizei length);
        void (*glShaderSource)(
            GLuint shader,
            GLsizei count,
            const GLchar *const *string,
            const GLint *length);
        void (*glShaderStorageBlockBinding)(
            GLuint program,
            GLuint storageBlockIndex,
            GLuint storageBlockBinding);
        void (*glSpecializeShader)(
            GLuint shader,
            const GLchar *pEntryPoint,
            GLuint numSpecializationConstants,
            const GLuint *pConstantIndex,
            const GLuint *pConstantValue);
        void (
            *glStencilFunc)(GLenum func, GLint ref, GLuint mask);
        void (*glStencilFuncSeparate)(
            GLenum face,
            GLenum func,
            GLint ref,
            GLuint mask);
        void (*glStencilMask)(GLuint mask);
        void (*glStencilMaskSeparate)(GLenum face, GLuint mask);
        void (*glStencilOp)(
            GLenum fail,
            GLenum zfail,
            GLenum zpass);
        void (*glStencilOpSeparate)(
            GLenum face,
            GLenum sfail,
            GLenum dpfail,
            GLenum dppass);
        void (*glTexBuffer)(
            GLenum target,
            GLenum internalformat,
            GLuint buffer);
        void (*glTexBufferRange)(
            GLenum target,
            GLenum internalformat,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*glTexImage1D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTexImage2D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLsizei height,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTexImage2DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*glTexImage3D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTexImage3DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*glTexParameterIiv)(
            GLenum target,
            GLenum pname,
            const GLint *params);
        void (*glTexParameterIuiv)(
            GLenum target,
            GLenum pname,
            const GLuint *params);
        void (*glTexParameterf)(
            GLenum target,
            GLenum pname,
            GLfloat param);
        void (*glTexParameterfv)(
            GLenum target,
            GLenum pname,
            const GLfloat *params);
        void (*glTexParameteri)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*glTexParameteriv)(
            GLenum target,
            GLenum pname,
            const GLint *params);
        void (*glTexStorage1D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width);
        void (*glTexStorage2D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glTexStorage2DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*glTexStorage3D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*glTexStorage3DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*glTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTextureBarrier)(void);
        void (*glTextureBuffer)(
            GLuint texture,
            GLenum internalformat,
            GLuint buffer);
        void (*glTextureBufferRange)(
            GLuint texture,
            GLenum internalformat,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*glTextureParameterIiv)(
            GLuint texture,
            GLenum pname,
            const GLint *params);
        void (*glTextureParameterIuiv)(
            GLuint texture,
            GLenum pname,
            const GLuint *params);
        void (*glTextureParameterf)(
            GLuint texture,
            GLenum pname,
            GLfloat param);
        void (*glTextureParameterfv)(
            GLuint texture,
            GLenum pname,
            const GLfloat *param);
        void (*glTextureParameteri)(
            GLuint texture,
            GLenum pname,
            GLint param);
        void (*glTextureParameteriv)(
            GLuint texture,
            GLenum pname,
            const GLint *param);
        void (*glTextureStorage1D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width);
        void (*glTextureStorage2D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*glTextureStorage2DMultisample)(
            GLuint texture,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*glTextureStorage3D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*glTextureStorage3DMultisample)(
            GLuint texture,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*glTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*glTextureView)(
            GLuint texture,
            GLenum target,
            GLuint origtexture,
            GLenum internalformat,
            GLuint minlevel,
            GLuint numlevels,
            GLuint minlayer,
            GLuint numlayers);
        void (*glTransformFeedbackBufferBase)(
            GLuint xfb,
            GLuint index,
            GLuint buffer);
        void (*glTransformFeedbackBufferRange)(
            GLuint xfb,
            GLuint index,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*glTransformFeedbackVaryings)(
            GLuint program,
            GLsizei count,
            const GLchar *const *varyings,
            GLenum bufferMode);
        void (*glUniform1d)(GLint location, GLdouble x);
        void (*glUniform1dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glUniform1f)(GLint location, GLfloat v0);
        void (*glUniform1fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glUniform1i)(GLint location, GLint v0);
        void (*glUniform1iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glUniform1ui)(GLint location, GLuint v0);
        void (*glUniform1uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glUniform2d)(
            GLint location,
            GLdouble x,
            GLdouble y);
        void (*glUniform2dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glUniform2f)(
            GLint location,
            GLfloat v0,
            GLfloat v1);
        void (*glUniform2fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glUniform2i)(GLint location, GLint v0, GLint v1);
        void (*glUniform2iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (
            *glUniform2ui)(GLint location, GLuint v0, GLuint v1);
        void (*glUniform2uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glUniform3d)(
            GLint location,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (*glUniform3dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glUniform3f)(
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2);
        void (*glUniform3fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glUniform3i)(
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2);
        void (*glUniform3iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glUniform3ui)(
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2);
        void (*glUniform3uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glUniform4d)(
            GLint location,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (*glUniform4dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*glUniform4f)(
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2,
            GLfloat v3);
        void (*glUniform4fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*glUniform4i)(
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2,
            GLint v3);
        void (*glUniform4iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*glUniform4ui)(
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2,
            GLuint v3);
        void (*glUniform4uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*glUniformBlockBinding)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLuint uniformBlockBinding);
        void (*glUniformMatrix2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix2x3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix2x3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix2x4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix2x4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix3x2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix3x2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix3x4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix3x4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix4x2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix4x2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformMatrix4x3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*glUniformMatrix4x3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*glUniformSubroutinesuiv)(
            GLenum shadertype,
            GLsizei count,
            const GLuint *indices);
        void (*glUseProgram)(GLuint program);
        void (*glUseProgramStages)(
            GLuint pipeline,
            GLbitfield stages,
            GLuint program);
        void (*glValidateProgram)(GLuint program);
        void (*glValidateProgramPipeline)(GLuint pipeline);
        void (*glVertexArrayAttribBinding)(
            GLuint vaobj,
            GLuint attribindex,
            GLuint bindingindex);
        void (*glVertexArrayAttribFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLuint relativeoffset);
        void (*glVertexArrayAttribIFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*glVertexArrayAttribLFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*glVertexArrayBindingDivisor)(
            GLuint vaobj,
            GLuint bindingindex,
            GLuint divisor);
        void (*glVertexArrayElementBuffer)(
            GLuint vaobj,
            GLuint buffer);
        void (*glVertexArrayVertexBuffer)(
            GLuint vaobj,
            GLuint bindingindex,
            GLuint buffer,
            GLintptr offset,
            GLsizei stride);
        void (*glVertexArrayVertexBuffers)(
            GLuint vaobj,
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizei *strides);
        void (*glVertexAttrib1d)(GLuint index, GLdouble x);
        void (
            *glVertexAttrib1dv)(GLuint index, const GLdouble *v);
        void (*glVertexAttrib1f)(GLuint index, GLfloat x);
        void (
            *glVertexAttrib1fv)(GLuint index, const GLfloat *v);
        void (*glVertexAttrib1s)(GLuint index, GLshort x);
        void (
            *glVertexAttrib1sv)(GLuint index, const GLshort *v);
        void (*glVertexAttrib2d)(
            GLuint index,
            GLdouble x,
            GLdouble y);
        void (
            *glVertexAttrib2dv)(GLuint index, const GLdouble *v);
        void (*glVertexAttrib2f)(
            GLuint index,
            GLfloat x,
            GLfloat y);
        void (
            *glVertexAttrib2fv)(GLuint index, const GLfloat *v);
        void (*glVertexAttrib2s)(
            GLuint index,
            GLshort x,
            GLshort y);
        void (
            *glVertexAttrib2sv)(GLuint index, const GLshort *v);
        void (*glVertexAttrib3d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (
            *glVertexAttrib3dv)(GLuint index, const GLdouble *v);
        void (*glVertexAttrib3f)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat z);
        void (
            *glVertexAttrib3fv)(GLuint index, const GLfloat *v);
        void (*glVertexAttrib3s)(
            GLuint index,
            GLshort x,
            GLshort y,
            GLshort z);
        void (
            *glVertexAttrib3sv)(GLuint index, const GLshort *v);
        void (
            *glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
        void (*glVertexAttrib4Niv)(GLuint index, const GLint *v);
        void (
            *glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
        void (*glVertexAttrib4Nub)(
            GLuint index,
            GLubyte x,
            GLubyte y,
            GLubyte z,
            GLubyte w);
        void (*glVertexAttrib4Nubv)(
            GLuint index,
            const GLubyte *v);
        void (
            *glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
        void (*glVertexAttrib4Nusv)(
            GLuint index,
            const GLushort *v);
        void (*glVertexAttrib4bv)(GLuint index, const GLbyte *v);
        void (*glVertexAttrib4d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (
            *glVertexAttrib4dv)(GLuint index, const GLdouble *v);
        void (*glVertexAttrib4f)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat z,
            GLfloat w);
        void (
            *glVertexAttrib4fv)(GLuint index, const GLfloat *v);
        void (*glVertexAttrib4iv)(GLuint index, const GLint *v);
        void (*glVertexAttrib4s)(
            GLuint index,
            GLshort x,
            GLshort y,
            GLshort z,
            GLshort w);
        void (
            *glVertexAttrib4sv)(GLuint index, const GLshort *v);
        void (
            *glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
        void (
            *glVertexAttrib4uiv)(GLuint index, const GLuint *v);
        void (*glVertexAttrib4usv)(
            GLuint index,
            const GLushort *v);
        void (*glVertexAttribBinding)(
            GLuint attribindex,
            GLuint bindingindex);
        void (*glVertexAttribDivisor)(
            GLuint index,
            GLuint divisor);
        void (*glVertexAttribFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLuint relativeoffset);
        void (*glVertexAttribI1i)(GLuint index, GLint x);
        void (*glVertexAttribI1iv)(GLuint index, const GLint *v);
        void (*glVertexAttribI1ui)(GLuint index, GLuint x);
        void (
            *glVertexAttribI1uiv)(GLuint index, const GLuint *v);
        void (
            *glVertexAttribI2i)(GLuint index, GLint x, GLint y);
        void (*glVertexAttribI2iv)(GLuint index, const GLint *v);
        void (*glVertexAttribI2ui)(
            GLuint index,
            GLuint x,
            GLuint y);
        void (
            *glVertexAttribI2uiv)(GLuint index, const GLuint *v);
        void (*glVertexAttribI3i)(
            GLuint index,
            GLint x,
            GLint y,
            GLint z);
        void (*glVertexAttribI3iv)(GLuint index, const GLint *v);
        void (*glVertexAttribI3ui)(
            GLuint index,
            GLuint x,
            GLuint y,
            GLuint z);
        void (
            *glVertexAttribI3uiv)(GLuint index, const GLuint *v);
        void (
            *glVertexAttribI4bv)(GLuint index, const GLbyte *v);
        void (*glVertexAttribI4i)(
            GLuint index,
            GLint x,
            GLint y,
            GLint z,
            GLint w);
        void (*glVertexAttribI4iv)(GLuint index, const GLint *v);
        void (
            *glVertexAttribI4sv)(GLuint index, const GLshort *v);
        void (*glVertexAttribI4ubv)(
            GLuint index,
            const GLubyte *v);
        void (*glVertexAttribI4ui)(
            GLuint index,
            GLuint x,
            GLuint y,
            GLuint z,
            GLuint w);
        void (
            *glVertexAttribI4uiv)(GLuint index, const GLuint *v);
        void (*glVertexAttribI4usv)(
            GLuint index,
            const GLushort *v);
        void (*glVertexAttribIFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*glVertexAttribIPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLsizei stride,
            const void *pointer);
        void (*glVertexAttribL1d)(GLuint index, GLdouble x);
        void (*glVertexAttribL1dv)(
            GLuint index,
            const GLdouble *v);
        void (*glVertexAttribL2d)(
            GLuint index,
            GLdouble x,
            GLdouble y);
        void (*glVertexAttribL2dv)(
            GLuint index,
            const GLdouble *v);
        void (*glVertexAttribL3d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (*glVertexAttribL3dv)(
            GLuint index,
            const GLdouble *v);
        void (*glVertexAttribL4d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (*glVertexAttribL4dv)(
            GLuint index,
            const GLdouble *v);
        void (*glVertexAttribLFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*glVertexAttribLPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLsizei stride,
            const void *pointer);
        void (*glVertexAttribP1ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*glVertexAttribP1uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*glVertexAttribP2ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*glVertexAttribP2uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*glVertexAttribP3ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*glVertexAttribP3uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*glVertexAttribP4ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*glVertexAttribP4uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*glVertexAttribPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLsizei stride,
            const void *pointer);
        void (*glVertexBindingDivisor)(
            GLuint bindingindex,
            GLuint divisor);
        void (*glViewport)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*glViewportArrayv)(
            GLuint first,
            GLsizei count,
            const GLfloat *v);
        void (*glViewportIndexedf)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat w,
            GLfloat h);
        void (*glViewportIndexedfv)(
            GLuint index,
            const GLfloat *v);
        void (*glWaitSync)(
            GLsync sync,
            GLbitfield flags,
            GLuint64 timeout);
        void *(*glMapBuffer)(GLenum target, GLenum access);
        void *(*glMapBufferRange)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr length,
            GLbitfield access);
        void *(*glMapNamedBuffer)(GLuint buffer, GLenum access);
        void *(*glMapNamedBufferRange)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length,
            GLbitfield access);
    } sysv;
    struct {
        GLboolean (*__attribute__((__ms_abi__)) glIsBuffer)(
            GLuint buffer);
        GLboolean (*__attribute__((__ms_abi__)) glIsEnabled)(
            GLenum cap);
        GLboolean (*__attribute__((__ms_abi__)) glIsEnabledi)(
            GLenum target,
            GLuint index);
        GLboolean (*__attribute__((__ms_abi__)) glIsFramebuffer)(
            GLuint framebuffer);
        GLboolean (*__attribute__((__ms_abi__)) glIsProgram)(
            GLuint program);
        GLboolean (*__attribute__((
            __ms_abi__)) glIsProgramPipeline)(GLuint pipeline);
        GLboolean (*__attribute__((__ms_abi__)) glIsQuery)(
            GLuint id);
        GLboolean (*__attribute__((
            __ms_abi__)) glIsRenderbuffer)(GLuint renderbuffer);
        GLboolean (*__attribute__((__ms_abi__)) glIsSampler)(
            GLuint sampler);
        GLboolean (*__attribute__((__ms_abi__)) glIsShader)(
            GLuint shader);
        GLboolean (*__attribute__((__ms_abi__)) glIsSync)(
            GLsync sync);
        GLboolean (*__attribute__((__ms_abi__)) glIsTexture)(
            GLuint texture);
        GLboolean (*__attribute__((
            __ms_abi__)) glIsTransformFeedback)(GLuint id);
        GLboolean (*__attribute__((__ms_abi__)) glIsVertexArray)(
            GLuint array);
        GLboolean (*__attribute__((__ms_abi__)) glUnmapBuffer)(
            GLenum target);
        GLboolean (*__attribute__((
            __ms_abi__)) glUnmapNamedBuffer)(GLuint buffer);
        GLenum (*__attribute__((__ms_abi__))
                glCheckFramebufferStatus)(GLenum target);
        GLenum (*__attribute__((
            __ms_abi__)) glCheckNamedFramebufferStatus)(
            GLuint framebuffer,
            GLenum target);
        GLenum (*__attribute__((__ms_abi__)) glClientWaitSync)(
            GLsync sync,
            GLbitfield flags,
            GLuint64 timeout);
        GLenum (*__attribute__((__ms_abi__)) glGetError)(void);
        GLenum (*__attribute__((
            __ms_abi__)) glGetGraphicsResetStatus)(void);
        GLint (*__attribute__((__ms_abi__)) glGetAttribLocation)(
            GLuint program,
            const GLchar *name);
        GLint (*__attribute__((__ms_abi__)) glGetFragDataIndex)(
            GLuint program,
            const GLchar *name);
        GLint (*__attribute__((
            __ms_abi__)) glGetFragDataLocation)(
            GLuint program,
            const GLchar *name);
        GLint (*__attribute__((
            __ms_abi__)) glGetProgramResourceLocation)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLint (*__attribute__((
            __ms_abi__)) glGetProgramResourceLocationIndex)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLint (*__attribute__((
            __ms_abi__)) glGetSubroutineUniformLocation)(
            GLuint program,
            GLenum shadertype,
            const GLchar *name);
        GLint (*__attribute__((
            __ms_abi__)) glGetUniformLocation)(
            GLuint program,
            const GLchar *name);
        GLsync (*__attribute__((__ms_abi__)) glFenceSync)(
            GLenum condition,
            GLbitfield flags);
        GLuint (*__attribute__((__ms_abi__)) glCreateProgram)(
            void);
        GLuint (*__attribute__((__ms_abi__)) glCreateShader)(
            GLenum type);
        GLuint (*__attribute__((
            __ms_abi__)) glCreateShaderProgramv)(
            GLenum type,
            GLsizei count,
            const GLchar *const *strings);
        GLuint (*__attribute__((
            __ms_abi__)) glGetDebugMessageLog)(
            GLuint count,
            GLsizei bufSize,
            GLenum *sources,
            GLenum *types,
            GLuint *ids,
            GLenum *severities,
            GLsizei *lengths,
            GLchar *messageLog);
        GLuint (*__attribute__((
            __ms_abi__)) glGetProgramResourceIndex)(
            GLuint program,
            GLenum programInterface,
            const GLchar *name);
        GLuint (*__attribute__((
            __ms_abi__)) glGetSubroutineIndex)(
            GLuint program,
            GLenum shadertype,
            const GLchar *name);
        GLuint (*__attribute__((
            __ms_abi__)) glGetUniformBlockIndex)(
            GLuint program,
            const GLchar *uniformBlockName);
        const GLubyte *(*__attribute__((
            __ms_abi__)) glGetString)(GLenum name);
        const GLubyte *(*__attribute__((__ms_abi__))
                        glGetStringi)(GLenum name, GLuint index);
        void (*__attribute__((
            __ms_abi__)) glActiveShaderProgram)(
            GLuint pipeline,
            GLuint program);
        void (*__attribute__((__ms_abi__)) glActiveTexture)(
            GLenum texture);
        void (*__attribute__((__ms_abi__)) glAttachShader)(
            GLuint program,
            GLuint shader);
        void (*__attribute__((__ms_abi__))
              glBeginConditionalRender)(GLuint id, GLenum mode);
        void (*__attribute__((
            __ms_abi__)) glBeginQuery)(GLenum target, GLuint id);
        void (*__attribute__((__ms_abi__)) glBeginQueryIndexed)(
            GLenum target,
            GLuint index,
            GLuint id);
        void (*__attribute__((__ms_abi__))
              glBeginTransformFeedback)(GLenum primitiveMode);
        void (*__attribute__((__ms_abi__)) glBindAttribLocation)(
            GLuint program,
            GLuint index,
            const GLchar *name);
        void (*__attribute__((__ms_abi__)) glBindBuffer)(
            GLenum target,
            GLuint buffer);
        void (*__attribute__((__ms_abi__)) glBindBufferBase)(
            GLenum target,
            GLuint index,
            GLuint buffer);
        void (*__attribute__((__ms_abi__)) glBindBufferRange)(
            GLenum target,
            GLuint index,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*__attribute__((__ms_abi__)) glBindBuffersBase)(
            GLenum target,
            GLuint first,
            GLsizei count,
            const GLuint *buffers);
        void (*__attribute__((__ms_abi__)) glBindBuffersRange)(
            GLenum target,
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizeiptr *sizes);
        void (*__attribute__((
            __ms_abi__)) glBindFragDataLocation)(
            GLuint program,
            GLuint color,
            const GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glBindFragDataLocationIndexed)(
            GLuint program,
            GLuint colorNumber,
            GLuint index,
            const GLchar *name);
        void (*__attribute__((__ms_abi__)) glBindFramebuffer)(
            GLenum target,
            GLuint framebuffer);
        void (*__attribute__((__ms_abi__)) glBindImageTexture)(
            GLuint unit,
            GLuint texture,
            GLint level,
            GLboolean layered,
            GLint layer,
            GLenum access,
            GLenum format);
        void (*__attribute__((__ms_abi__)) glBindImageTextures)(
            GLuint first,
            GLsizei count,
            const GLuint *textures);
        void (*__attribute__((
            __ms_abi__)) glBindProgramPipeline)(GLuint pipeline);
        void (*__attribute__((__ms_abi__)) glBindRenderbuffer)(
            GLenum target,
            GLuint renderbuffer);
        void (*__attribute__((__ms_abi__)) glBindSampler)(
            GLuint unit,
            GLuint sampler);
        void (*__attribute__((__ms_abi__)) glBindSamplers)(
            GLuint first,
            GLsizei count,
            const GLuint *samplers);
        void (*__attribute__((__ms_abi__)) glBindTexture)(
            GLenum target,
            GLuint texture);
        void (*__attribute__((__ms_abi__)) glBindTextureUnit)(
            GLuint unit,
            GLuint texture);
        void (*__attribute__((__ms_abi__)) glBindTextures)(
            GLuint first,
            GLsizei count,
            const GLuint *textures);
        void (*__attribute__((__ms_abi__))
              glBindTransformFeedback)(GLenum target, GLuint id);
        void (*__attribute__((__ms_abi__)) glBindVertexArray)(
            GLuint array);
        void (*__attribute__((__ms_abi__)) glBindVertexBuffer)(
            GLuint bindingindex,
            GLuint buffer,
            GLintptr offset,
            GLsizei stride);
        void (*__attribute__((__ms_abi__)) glBindVertexBuffers)(
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizei *strides);
        void (*__attribute__((__ms_abi__)) glBlendColor)(
            GLfloat red,
            GLfloat green,
            GLfloat blue,
            GLfloat alpha);
        void (*__attribute__((__ms_abi__)) glBlendEquation)(
            GLenum mode);
        void (*__attribute__((
            __ms_abi__)) glBlendEquationSeparate)(
            GLenum modeRGB,
            GLenum modeAlpha);
        void (*__attribute__((
            __ms_abi__)) glBlendEquationSeparatei)(
            GLuint buf,
            GLenum modeRGB,
            GLenum modeAlpha);
        void (*__attribute__((__ms_abi__)) glBlendEquationi)(
            GLuint buf,
            GLenum mode);
        void (*__attribute__((__ms_abi__)) glBlendFunc)(
            GLenum sfactor,
            GLenum dfactor);
        void (*__attribute__((__ms_abi__)) glBlendFuncSeparate)(
            GLenum sfactorRGB,
            GLenum dfactorRGB,
            GLenum sfactorAlpha,
            GLenum dfactorAlpha);
        void (*__attribute__((__ms_abi__)) glBlendFuncSeparatei)(
            GLuint buf,
            GLenum srcRGB,
            GLenum dstRGB,
            GLenum srcAlpha,
            GLenum dstAlpha);
        void (*__attribute__((__ms_abi__)) glBlendFunci)(
            GLuint buf,
            GLenum src,
            GLenum dst);
        void (*__attribute__((__ms_abi__)) glBlitFramebuffer)(
            GLint srcX0,
            GLint srcY0,
            GLint srcX1,
            GLint srcY1,
            GLint dstX0,
            GLint dstY0,
            GLint dstX1,
            GLint dstY1,
            GLbitfield mask,
            GLenum filter);
        void (*__attribute__((
            __ms_abi__)) glBlitNamedFramebuffer)(
            GLuint readFramebuffer,
            GLuint drawFramebuffer,
            GLint srcX0,
            GLint srcY0,
            GLint srcX1,
            GLint srcY1,
            GLint dstX0,
            GLint dstY0,
            GLint dstX1,
            GLint dstY1,
            GLbitfield mask,
            GLenum filter);
        void (*__attribute__((__ms_abi__)) glBufferData)(
            GLenum target,
            GLsizeiptr size,
            const void *data,
            GLenum usage);
        void (*__attribute__((__ms_abi__)) glBufferStorage)(
            GLenum target,
            GLsizeiptr size,
            const void *data,
            GLbitfield flags);
        void (*__attribute__((__ms_abi__)) glBufferSubData)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr size,
            const void *data);
        void (*__attribute__((__ms_abi__)) glClampColor)(
            GLenum target,
            GLenum clamp);
        void (*__attribute__((__ms_abi__)) glClear)(
            GLbitfield mask);
        void (*__attribute__((__ms_abi__)) glClearBufferData)(
            GLenum target,
            GLenum internalformat,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((__ms_abi__)) glClearBufferSubData)(
            GLenum target,
            GLenum internalformat,
            GLintptr offset,
            GLsizeiptr size,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((__ms_abi__)) glClearBufferfi)(
            GLenum buffer,
            GLint drawbuffer,
            GLfloat depth,
            GLint stencil);
        void (*__attribute__((__ms_abi__)) glClearBufferfv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glClearBufferiv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glClearBufferuiv)(
            GLenum buffer,
            GLint drawbuffer,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glClearColor)(
            GLfloat red,
            GLfloat green,
            GLfloat blue,
            GLfloat alpha);
        void (*__attribute__((__ms_abi__)) glClearDepth)(
            GLdouble depth);
        void (*__attribute__((__ms_abi__)) glClearDepthf)(
            GLfloat d);
        void (*__attribute__((
            __ms_abi__)) glClearNamedBufferData)(
            GLuint buffer,
            GLenum internalformat,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glClearNamedBufferSubData)(
            GLuint buffer,
            GLenum internalformat,
            GLintptr offset,
            GLsizeiptr size,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glClearNamedFramebufferfi)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            GLfloat depth,
            GLint stencil);
        void (*__attribute__((
            __ms_abi__)) glClearNamedFramebufferfv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glClearNamedFramebufferiv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLint *value);
        void (*__attribute__((
            __ms_abi__)) glClearNamedFramebufferuiv)(
            GLuint framebuffer,
            GLenum buffer,
            GLint drawbuffer,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glClearStencil)(
            GLint s);
        void (*__attribute__((__ms_abi__)) glClearTexImage)(
            GLuint texture,
            GLint level,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((__ms_abi__)) glClearTexSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *data);
        void (*__attribute__((__ms_abi__)) glClipControl)(
            GLenum origin,
            GLenum depth);
        void (*__attribute__((__ms_abi__)) glColorMask)(
            GLboolean red,
            GLboolean green,
            GLboolean blue,
            GLboolean alpha);
        void (*__attribute__((__ms_abi__)) glColorMaski)(
            GLuint index,
            GLboolean r,
            GLboolean g,
            GLboolean b,
            GLboolean a);
        void (*__attribute__((__ms_abi__)) glCompileShader)(
            GLuint shader);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexImage1D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexImage2D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexImage3D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLint border,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glCompressedTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLsizei imageSize,
            const void *data);
        void (*__attribute__((__ms_abi__)) glCopyBufferSubData)(
            GLenum readTarget,
            GLenum writeTarget,
            GLintptr readOffset,
            GLintptr writeOffset,
            GLsizeiptr size);
        void (*__attribute__((__ms_abi__)) glCopyImageSubData)(
            GLuint srcName,
            GLenum srcTarget,
            GLint srcLevel,
            GLint srcX,
            GLint srcY,
            GLint srcZ,
            GLuint dstName,
            GLenum dstTarget,
            GLint dstLevel,
            GLint dstX,
            GLint dstY,
            GLint dstZ,
            GLsizei srcWidth,
            GLsizei srcHeight,
            GLsizei srcDepth);
        void (*__attribute__((
            __ms_abi__)) glCopyNamedBufferSubData)(
            GLuint readBuffer,
            GLuint writeBuffer,
            GLintptr readOffset,
            GLintptr writeOffset,
            GLsizeiptr size);
        void (*__attribute__((__ms_abi__)) glCopyTexImage1D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLint x,
            GLint y,
            GLsizei width,
            GLint border);
        void (*__attribute__((__ms_abi__)) glCopyTexImage2D)(
            GLenum target,
            GLint level,
            GLenum internalformat,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLint border);
        void (*__attribute__((__ms_abi__)) glCopyTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint x,
            GLint y,
            GLsizei width);
        void (*__attribute__((__ms_abi__)) glCopyTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glCopyTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glCopyTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint x,
            GLint y,
            GLsizei width);
        void (*__attribute__((
            __ms_abi__)) glCopyTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glCopyTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glCreateBuffers)(
            GLsizei n,
            GLuint *buffers);
        void (*__attribute__((__ms_abi__)) glCreateFramebuffers)(
            GLsizei n,
            GLuint *framebuffers);
        void (*__attribute__((
            __ms_abi__)) glCreateProgramPipelines)(
            GLsizei n,
            GLuint *pipelines);
        void (*__attribute__((__ms_abi__)) glCreateQueries)(
            GLenum target,
            GLsizei n,
            GLuint *ids);
        void (*__attribute__((
            __ms_abi__)) glCreateRenderbuffers)(
            GLsizei n,
            GLuint *renderbuffers);
        void (*__attribute__((__ms_abi__)) glCreateSamplers)(
            GLsizei n,
            GLuint *samplers);
        void (*__attribute__((__ms_abi__)) glCreateTextures)(
            GLenum target,
            GLsizei n,
            GLuint *textures);
        void (*__attribute__((
            __ms_abi__)) glCreateTransformFeedbacks)(
            GLsizei n,
            GLuint *ids);
        void (*__attribute__((__ms_abi__)) glCreateVertexArrays)(
            GLsizei n,
            GLuint *arrays);
        void (*__attribute__((__ms_abi__)) glCullFace)(
            GLenum mode);
        void (*__attribute__((
            __ms_abi__)) glDebugMessageCallback)(
            GLDEBUGPROC callback,
            const void *userParam);
        void (*__attribute__((
            __ms_abi__)) glDebugMessageControl)(
            GLenum source,
            GLenum type,
            GLenum severity,
            GLsizei count,
            const GLuint *ids,
            GLboolean enabled);
        void (*__attribute__((__ms_abi__)) glDebugMessageInsert)(
            GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar *buf);
        void (*__attribute__((__ms_abi__)) glDeleteBuffers)(
            GLsizei n,
            const GLuint *buffers);
        void (*__attribute__((__ms_abi__)) glDeleteFramebuffers)(
            GLsizei n,
            const GLuint *framebuffers);
        void (*__attribute__((__ms_abi__)) glDeleteProgram)(
            GLuint program);
        void (*__attribute__((
            __ms_abi__)) glDeleteProgramPipelines)(
            GLsizei n,
            const GLuint *pipelines);
        void (*__attribute__((__ms_abi__)) glDeleteQueries)(
            GLsizei n,
            const GLuint *ids);
        void (*__attribute__((
            __ms_abi__)) glDeleteRenderbuffers)(
            GLsizei n,
            const GLuint *renderbuffers);
        void (*__attribute__((__ms_abi__)) glDeleteSamplers)(
            GLsizei count,
            const GLuint *samplers);
        void (*__attribute__((__ms_abi__)) glDeleteShader)(
            GLuint shader);
        void (*__attribute__((__ms_abi__)) glDeleteSync)(
            GLsync sync);
        void (*__attribute__((__ms_abi__)) glDeleteTextures)(
            GLsizei n,
            const GLuint *textures);
        void (*__attribute__((
            __ms_abi__)) glDeleteTransformFeedbacks)(
            GLsizei n,
            const GLuint *ids);
        void (*__attribute__((__ms_abi__)) glDeleteVertexArrays)(
            GLsizei n,
            const GLuint *arrays);
        void (*__attribute__((__ms_abi__)) glDepthFunc)(
            GLenum func);
        void (*__attribute__((__ms_abi__)) glDepthMask)(
            GLboolean flag);
        void (*__attribute__((
            __ms_abi__)) glDepthRange)(GLdouble n, GLdouble f);
        void (*__attribute__((__ms_abi__)) glDepthRangeArrayv)(
            GLuint first,
            GLsizei count,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glDepthRangeIndexed)(
            GLuint index,
            GLdouble n,
            GLdouble f);
        void (*__attribute__((
            __ms_abi__)) glDepthRangef)(GLfloat n, GLfloat f);
        void (*__attribute__((__ms_abi__)) glDetachShader)(
            GLuint program,
            GLuint shader);
        void (*__attribute__((__ms_abi__)) glDisable)(
            GLenum cap);
        void (*__attribute__((
            __ms_abi__)) glDisableVertexArrayAttrib)(
            GLuint vaobj,
            GLuint index);
        void (*__attribute__((__ms_abi__))
              glDisableVertexAttribArray)(GLuint index);
        void (*__attribute__((__ms_abi__)) glDisablei)(
            GLenum target,
            GLuint index);
        void (*__attribute__((__ms_abi__)) glDispatchCompute)(
            GLuint num_groups_x,
            GLuint num_groups_y,
            GLuint num_groups_z);
        void (*__attribute__((__ms_abi__))
              glDispatchComputeIndirect)(GLintptr indirect);
        void (*__attribute__((__ms_abi__)) glDrawArrays)(
            GLenum mode,
            GLint first,
            GLsizei count);
        void (*__attribute__((__ms_abi__)) glDrawArraysIndirect)(
            GLenum mode,
            const void *indirect);
        void (*__attribute__((
            __ms_abi__)) glDrawArraysInstanced)(
            GLenum mode,
            GLint first,
            GLsizei count,
            GLsizei instancecount);
        void (*__attribute__((
            __ms_abi__)) glDrawArraysInstancedBaseInstance)(
            GLenum mode,
            GLint first,
            GLsizei count,
            GLsizei instancecount,
            GLuint baseinstance);
        void (*__attribute__((__ms_abi__)) glDrawBuffer)(
            GLenum buf);
        void (*__attribute__((__ms_abi__)) glDrawBuffers)(
            GLsizei n,
            const GLenum *bufs);
        void (*__attribute__((__ms_abi__)) glDrawElements)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices);
        void (*__attribute__((
            __ms_abi__)) glDrawElementsBaseVertex)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLint basevertex);
        void (*__attribute__((
            __ms_abi__)) glDrawElementsIndirect)(
            GLenum mode,
            GLenum type,
            const void *indirect);
        void (*__attribute__((
            __ms_abi__)) glDrawElementsInstanced)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount);
        void (*__attribute__((
            __ms_abi__)) glDrawElementsInstancedBaseInstance)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLuint baseinstance);
        void (*__attribute__((
            __ms_abi__)) glDrawElementsInstancedBaseVertex)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLint basevertex);
        void (*__attribute__((__ms_abi__))
              glDrawElementsInstancedBaseVertexBaseInstance)(
            GLenum mode,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLsizei instancecount,
            GLint basevertex,
            GLuint baseinstance);
        void (*__attribute__((__ms_abi__)) glDrawRangeElements)(
            GLenum mode,
            GLuint start,
            GLuint end,
            GLsizei count,
            GLenum type,
            const void *indices);
        void (*__attribute__((
            __ms_abi__)) glDrawRangeElementsBaseVertex)(
            GLenum mode,
            GLuint start,
            GLuint end,
            GLsizei count,
            GLenum type,
            const void *indices,
            GLint basevertex);
        void (*__attribute__((__ms_abi__))
              glDrawTransformFeedback)(GLenum mode, GLuint id);
        void (*__attribute__((
            __ms_abi__)) glDrawTransformFeedbackInstanced)(
            GLenum mode,
            GLuint id,
            GLsizei instancecount);
        void (*__attribute__((
            __ms_abi__)) glDrawTransformFeedbackStream)(
            GLenum mode,
            GLuint id,
            GLuint stream);
        void (*__attribute__((
            __ms_abi__)) glDrawTransformFeedbackStreamInstanced)(
            GLenum mode,
            GLuint id,
            GLuint stream,
            GLsizei instancecount);
        void (*__attribute__((__ms_abi__)) glEnable)(GLenum cap);
        void (*__attribute__((
            __ms_abi__)) glEnableVertexArrayAttrib)(
            GLuint vaobj,
            GLuint index);
        void (*__attribute__((__ms_abi__))
              glEnableVertexAttribArray)(GLuint index);
        void (*__attribute__((
            __ms_abi__)) glEnablei)(GLenum target, GLuint index);
        void (*__attribute__((
            __ms_abi__)) glEndConditionalRender)(void);
        void (*__attribute__((__ms_abi__)) glEndQuery)(
            GLenum target);
        void (*__attribute__((__ms_abi__)) glEndQueryIndexed)(
            GLenum target,
            GLuint index);
        void (*__attribute__((
            __ms_abi__)) glEndTransformFeedback)(void);
        void (*__attribute__((__ms_abi__)) glFinish)(void);
        void (*__attribute__((__ms_abi__)) glFlush)(void);
        void (*__attribute__((
            __ms_abi__)) glFlushMappedBufferRange)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr length);
        void (*__attribute__((
            __ms_abi__)) glFlushMappedNamedBufferRange)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length);
        void (*__attribute__((
            __ms_abi__)) glFramebufferParameteri)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*__attribute__((
            __ms_abi__)) glFramebufferParameteriMESA)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*__attribute__((
            __ms_abi__)) glFramebufferRenderbuffer)(
            GLenum target,
            GLenum attachment,
            GLenum renderbuffertarget,
            GLuint renderbuffer);
        void (*__attribute__((__ms_abi__)) glFramebufferTexture)(
            GLenum target,
            GLenum attachment,
            GLuint texture,
            GLint level);
        void (*__attribute__((
            __ms_abi__)) glFramebufferTexture1D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level);
        void (*__attribute__((
            __ms_abi__)) glFramebufferTexture2D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level);
        void (*__attribute__((
            __ms_abi__)) glFramebufferTexture3D)(
            GLenum target,
            GLenum attachment,
            GLenum textarget,
            GLuint texture,
            GLint level,
            GLint zoffset);
        void (*__attribute__((
            __ms_abi__)) glFramebufferTextureLayer)(
            GLenum target,
            GLenum attachment,
            GLuint texture,
            GLint level,
            GLint layer);
        void (*__attribute__((__ms_abi__)) glFrontFace)(
            GLenum mode);
        void (*__attribute__((__ms_abi__)) glGenBuffers)(
            GLsizei n,
            GLuint *buffers);
        void (*__attribute__((__ms_abi__)) glGenFramebuffers)(
            GLsizei n,
            GLuint *framebuffers);
        void (*__attribute__((
            __ms_abi__)) glGenProgramPipelines)(
            GLsizei n,
            GLuint *pipelines);
        void (*__attribute__((
            __ms_abi__)) glGenQueries)(GLsizei n, GLuint *ids);
        void (*__attribute__((__ms_abi__)) glGenRenderbuffers)(
            GLsizei n,
            GLuint *renderbuffers);
        void (*__attribute__((__ms_abi__)) glGenSamplers)(
            GLsizei count,
            GLuint *samplers);
        void (*__attribute__((__ms_abi__)) glGenTextures)(
            GLsizei n,
            GLuint *textures);
        void (*__attribute__((__ms_abi__))
              glGenTransformFeedbacks)(GLsizei n, GLuint *ids);
        void (*__attribute__((__ms_abi__)) glGenVertexArrays)(
            GLsizei n,
            GLuint *arrays);
        void (*__attribute__((__ms_abi__)) glGenerateMipmap)(
            GLenum target);
        void (*__attribute__((__ms_abi__))
              glGenerateTextureMipmap)(GLuint texture);
        void (*__attribute__((
            __ms_abi__)) glGetActiveAtomicCounterBufferiv)(
            GLuint program,
            GLuint bufferIndex,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetActiveAttrib)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLint *size,
            GLenum *type,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetActiveSubroutineName)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetActiveSubroutineUniformName)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetActiveSubroutineUniformiv)(
            GLuint program,
            GLenum shadertype,
            GLuint index,
            GLenum pname,
            GLint *values);
        void (*__attribute__((__ms_abi__)) glGetActiveUniform)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLint *size,
            GLenum *type,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetActiveUniformBlockName)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *uniformBlockName);
        void (*__attribute__((
            __ms_abi__)) glGetActiveUniformBlockiv)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetActiveUniformName)(
            GLuint program,
            GLuint uniformIndex,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *uniformName);
        void (*__attribute__((
            __ms_abi__)) glGetActiveUniformsiv)(
            GLuint program,
            GLsizei uniformCount,
            const GLuint *uniformIndices,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetAttachedShaders)(
            GLuint program,
            GLsizei maxCount,
            GLsizei *count,
            GLuint *shaders);
        void (*__attribute__((__ms_abi__)) glGetBooleani_v)(
            GLenum target,
            GLuint index,
            GLboolean *data);
        void (*__attribute__((__ms_abi__)) glGetBooleanv)(
            GLenum pname,
            GLboolean *data);
        void (*__attribute__((
            __ms_abi__)) glGetBufferParameteri64v)(
            GLenum target,
            GLenum pname,
            GLint64 *params);
        void (*__attribute__((
            __ms_abi__)) glGetBufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetBufferPointerv)(
            GLenum target,
            GLenum pname,
            void **params);
        void (*__attribute__((__ms_abi__)) glGetBufferSubData)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr size,
            void *data);
        void (*__attribute__((
            __ms_abi__)) glGetCompressedTexImage)(
            GLenum target,
            GLint level,
            void *img);
        void (*__attribute__((
            __ms_abi__)) glGetCompressedTextureImage)(
            GLuint texture,
            GLint level,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((
            __ms_abi__)) glGetCompressedTextureSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((__ms_abi__)) glGetDoublei_v)(
            GLenum target,
            GLuint index,
            GLdouble *data);
        void (*__attribute__((__ms_abi__)) glGetDoublev)(
            GLenum pname,
            GLdouble *data);
        void (*__attribute__((__ms_abi__)) glGetFloati_v)(
            GLenum target,
            GLuint index,
            GLfloat *data);
        void (*__attribute__((__ms_abi__)) glGetFloatv)(
            GLenum pname,
            GLfloat *data);
        void (*__attribute__((
            __ms_abi__)) glGetFramebufferAttachmentParameteriv)(
            GLenum target,
            GLenum attachment,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetFramebufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetFramebufferParameterivMESA)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetInteger64i_v)(
            GLenum target,
            GLuint index,
            GLint64 *data);
        void (*__attribute__((__ms_abi__)) glGetInteger64v)(
            GLenum pname,
            GLint64 *data);
        void (*__attribute__((__ms_abi__)) glGetIntegeri_v)(
            GLenum target,
            GLuint index,
            GLint *data);
        void (*__attribute__((__ms_abi__)) glGetIntegerv)(
            GLenum pname,
            GLint *data);
        void (*__attribute__((
            __ms_abi__)) glGetInternalformati64v)(
            GLenum target,
            GLenum internalformat,
            GLenum pname,
            GLsizei count,
            GLint64 *params);
        void (*__attribute__((
            __ms_abi__)) glGetInternalformativ)(
            GLenum target,
            GLenum internalformat,
            GLenum pname,
            GLsizei count,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetMultisamplefv)(
            GLenum pname,
            GLuint index,
            GLfloat *val);
        void (*__attribute__((
            __ms_abi__)) glGetNamedBufferParameteri64v)(
            GLuint buffer,
            GLenum pname,
            GLint64 *params);
        void (*__attribute__((
            __ms_abi__)) glGetNamedBufferParameteriv)(
            GLuint buffer,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetNamedBufferPointerv)(
            GLuint buffer,
            GLenum pname,
            void **params);
        void (*__attribute__((
            __ms_abi__)) glGetNamedBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size,
            void *data);
        void (*__attribute__((__ms_abi__))
              glGetNamedFramebufferAttachmentParameteriv)(
            GLuint framebuffer,
            GLenum attachment,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetNamedFramebufferParameteriv)(
            GLuint framebuffer,
            GLenum pname,
            GLint *param);
        void (*__attribute__((
            __ms_abi__)) glGetNamedRenderbufferParameteriv)(
            GLuint renderbuffer,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetObjectLabel)(
            GLenum identifier,
            GLuint name,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *label);
        void (*__attribute__((__ms_abi__)) glGetObjectPtrLabel)(
            const void *ptr,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *label);
        void (*__attribute__((__ms_abi__)) glGetPointerv)(
            GLenum pname,
            void **params);
        void (*__attribute__((__ms_abi__)) glGetProgramBinary)(
            GLuint program,
            GLsizei bufSize,
            GLsizei *length,
            GLenum *binaryFormat,
            void *binary);
        void (*__attribute__((__ms_abi__)) glGetProgramInfoLog)(
            GLuint program,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*__attribute__((
            __ms_abi__)) glGetProgramInterfaceiv)(
            GLuint program,
            GLenum programInterface,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetProgramPipelineInfoLog)(
            GLuint pipeline,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*__attribute__((
            __ms_abi__)) glGetProgramPipelineiv)(
            GLuint pipeline,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetProgramResourceName)(
            GLuint program,
            GLenum programInterface,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetProgramResourceiv)(
            GLuint program,
            GLenum programInterface,
            GLuint index,
            GLsizei propCount,
            const GLenum *props,
            GLsizei count,
            GLsizei *length,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetProgramStageiv)(
            GLuint program,
            GLenum shadertype,
            GLenum pname,
            GLint *values);
        void (*__attribute__((__ms_abi__)) glGetProgramiv)(
            GLuint program,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetQueryBufferObjecti64v)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*__attribute__((
            __ms_abi__)) glGetQueryBufferObjectiv)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*__attribute__((
            __ms_abi__)) glGetQueryBufferObjectui64v)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*__attribute__((
            __ms_abi__)) glGetQueryBufferObjectuiv)(
            GLuint id,
            GLuint buffer,
            GLenum pname,
            GLintptr offset);
        void (*__attribute__((__ms_abi__)) glGetQueryIndexediv)(
            GLenum target,
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetQueryObjecti64v)(
            GLuint id,
            GLenum pname,
            GLint64 *params);
        void (*__attribute__((__ms_abi__)) glGetQueryObjectiv)(
            GLuint id,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetQueryObjectui64v)(
            GLuint id,
            GLenum pname,
            GLuint64 *params);
        void (*__attribute__((__ms_abi__)) glGetQueryObjectuiv)(
            GLuint id,
            GLenum pname,
            GLuint *params);
        void (*__attribute__((__ms_abi__)) glGetQueryiv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetRenderbufferParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetSamplerParameterIiv)(
            GLuint sampler,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetSamplerParameterIuiv)(
            GLuint sampler,
            GLenum pname,
            GLuint *params);
        void (*__attribute__((
            __ms_abi__)) glGetSamplerParameterfv)(
            GLuint sampler,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((
            __ms_abi__)) glGetSamplerParameteriv)(
            GLuint sampler,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetShaderInfoLog)(
            GLuint shader,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *infoLog);
        void (*__attribute__((
            __ms_abi__)) glGetShaderPrecisionFormat)(
            GLenum shadertype,
            GLenum precisiontype,
            GLint *range,
            GLint *precision);
        void (*__attribute__((__ms_abi__)) glGetShaderSource)(
            GLuint shader,
            GLsizei bufSize,
            GLsizei *length,
            GLchar *source);
        void (*__attribute__((__ms_abi__)) glGetShaderiv)(
            GLuint shader,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetSynciv)(
            GLsync sync,
            GLenum pname,
            GLsizei count,
            GLsizei *length,
            GLint *values);
        void (*__attribute__((__ms_abi__)) glGetTexImage)(
            GLenum target,
            GLint level,
            GLenum format,
            GLenum type,
            void *pixels);
        void (*__attribute__((
            __ms_abi__)) glGetTexLevelParameterfv)(
            GLenum target,
            GLint level,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((
            __ms_abi__)) glGetTexLevelParameteriv)(
            GLenum target,
            GLint level,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetTexParameterIiv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetTexParameterIuiv)(
            GLenum target,
            GLenum pname,
            GLuint *params);
        void (*__attribute__((__ms_abi__)) glGetTexParameterfv)(
            GLenum target,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((__ms_abi__)) glGetTexParameteriv)(
            GLenum target,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetTextureImage)(
            GLuint texture,
            GLint level,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((
            __ms_abi__)) glGetTextureLevelParameterfv)(
            GLuint texture,
            GLint level,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((
            __ms_abi__)) glGetTextureLevelParameteriv)(
            GLuint texture,
            GLint level,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetTextureParameterIiv)(
            GLuint texture,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetTextureParameterIuiv)(
            GLuint texture,
            GLenum pname,
            GLuint *params);
        void (*__attribute__((
            __ms_abi__)) glGetTextureParameterfv)(
            GLuint texture,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((
            __ms_abi__)) glGetTextureParameteriv)(
            GLuint texture,
            GLenum pname,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetTextureSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((
            __ms_abi__)) glGetTransformFeedbackVarying)(
            GLuint program,
            GLuint index,
            GLsizei bufSize,
            GLsizei *length,
            GLsizei *size,
            GLenum *type,
            GLchar *name);
        void (*__attribute__((
            __ms_abi__)) glGetTransformFeedbacki64_v)(
            GLuint xfb,
            GLenum pname,
            GLuint index,
            GLint64 *param);
        void (*__attribute__((
            __ms_abi__)) glGetTransformFeedbacki_v)(
            GLuint xfb,
            GLenum pname,
            GLuint index,
            GLint *param);
        void (*__attribute__((
            __ms_abi__)) glGetTransformFeedbackiv)(
            GLuint xfb,
            GLenum pname,
            GLint *param);
        void (*__attribute__((__ms_abi__)) glGetUniformIndices)(
            GLuint program,
            GLsizei uniformCount,
            const GLchar *const *uniformNames,
            GLuint *uniformIndices);
        void (*__attribute__((
            __ms_abi__)) glGetUniformSubroutineuiv)(
            GLenum shadertype,
            GLint location,
            GLuint *params);
        void (*__attribute__((__ms_abi__)) glGetUniformdv)(
            GLuint program,
            GLint location,
            GLdouble *params);
        void (*__attribute__((__ms_abi__)) glGetUniformfv)(
            GLuint program,
            GLint location,
            GLfloat *params);
        void (*__attribute__((__ms_abi__)) glGetUniformiv)(
            GLuint program,
            GLint location,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetUniformuiv)(
            GLuint program,
            GLint location,
            GLuint *params);
        void (*__attribute__((
            __ms_abi__)) glGetVertexArrayIndexed64iv)(
            GLuint vaobj,
            GLuint index,
            GLenum pname,
            GLint64 *param);
        void (*__attribute__((
            __ms_abi__)) glGetVertexArrayIndexediv)(
            GLuint vaobj,
            GLuint index,
            GLenum pname,
            GLint *param);
        void (*__attribute__((__ms_abi__)) glGetVertexArrayiv)(
            GLuint vaobj,
            GLenum pname,
            GLint *param);
        void (*__attribute__((__ms_abi__)) glGetVertexAttribIiv)(
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetVertexAttribIuiv)(
            GLuint index,
            GLenum pname,
            GLuint *params);
        void (*__attribute__((__ms_abi__)) glGetVertexAttribLdv)(
            GLuint index,
            GLenum pname,
            GLdouble *params);
        void (*__attribute__((
            __ms_abi__)) glGetVertexAttribPointerv)(
            GLuint index,
            GLenum pname,
            void **pointer);
        void (*__attribute__((__ms_abi__)) glGetVertexAttribdv)(
            GLuint index,
            GLenum pname,
            GLdouble *params);
        void (*__attribute__((__ms_abi__)) glGetVertexAttribfv)(
            GLuint index,
            GLenum pname,
            GLfloat *params);
        void (*__attribute__((__ms_abi__)) glGetVertexAttribiv)(
            GLuint index,
            GLenum pname,
            GLint *params);
        void (*__attribute__((
            __ms_abi__)) glGetnCompressedTexImage)(
            GLenum target,
            GLint lod,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((__ms_abi__)) glGetnTexImage)(
            GLenum target,
            GLint level,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *pixels);
        void (*__attribute__((__ms_abi__)) glGetnUniformdv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLdouble *params);
        void (*__attribute__((__ms_abi__)) glGetnUniformfv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLfloat *params);
        void (*__attribute__((__ms_abi__)) glGetnUniformiv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLint *params);
        void (*__attribute__((__ms_abi__)) glGetnUniformuiv)(
            GLuint program,
            GLint location,
            GLsizei bufSize,
            GLuint *params);
        void (*__attribute__((
            __ms_abi__)) glHint)(GLenum target, GLenum mode);
        void (*__attribute__((
            __ms_abi__)) glInvalidateBufferData)(GLuint buffer);
        void (*__attribute__((
            __ms_abi__)) glInvalidateBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length);
        void (*__attribute__((
            __ms_abi__)) glInvalidateFramebuffer)(
            GLenum target,
            GLsizei numAttachments,
            const GLenum *attachments);
        void (*__attribute__((
            __ms_abi__)) glInvalidateNamedFramebufferData)(
            GLuint framebuffer,
            GLsizei numAttachments,
            const GLenum *attachments);
        void (*__attribute__((
            __ms_abi__)) glInvalidateNamedFramebufferSubData)(
            GLuint framebuffer,
            GLsizei numAttachments,
            const GLenum *attachments,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glInvalidateSubFramebuffer)(
            GLenum target,
            GLsizei numAttachments,
            const GLenum *attachments,
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glInvalidateTexImage)(
            GLuint texture,
            GLint level);
        void (*__attribute__((
            __ms_abi__)) glInvalidateTexSubImage)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*__attribute__((__ms_abi__)) glLineWidth)(
            GLfloat width);
        void (*__attribute__((__ms_abi__)) glLinkProgram)(
            GLuint program);
        void (*__attribute__((__ms_abi__)) glLogicOp)(
            GLenum opcode);
        void (*__attribute__((__ms_abi__)) glMemoryBarrier)(
            GLbitfield barriers);
        void (*__attribute__((__ms_abi__))
              glMemoryBarrierByRegion)(GLbitfield barriers);
        void (*__attribute__((__ms_abi__)) glMinSampleShading)(
            GLfloat value);
        void (*__attribute__((__ms_abi__)) glMultiDrawArrays)(
            GLenum mode,
            const GLint *first,
            const GLsizei *count,
            GLsizei drawcount);
        void (*__attribute__((
            __ms_abi__)) glMultiDrawArraysIndirect)(
            GLenum mode,
            const void *indirect,
            GLsizei drawcount,
            GLsizei stride);
        void (*__attribute__((
            __ms_abi__)) glMultiDrawArraysIndirectCount)(
            GLenum mode,
            const void *indirect,
            GLintptr drawcount,
            GLsizei maxdrawcount,
            GLsizei stride);
        void (*__attribute__((__ms_abi__)) glMultiDrawElements)(
            GLenum mode,
            const GLsizei *count,
            GLenum type,
            const void *const *indices,
            GLsizei drawcount);
        void (*__attribute__((
            __ms_abi__)) glMultiDrawElementsBaseVertex)(
            GLenum mode,
            const GLsizei *count,
            GLenum type,
            const void *const *indices,
            GLsizei drawcount,
            const GLint *basevertex);
        void (*__attribute__((
            __ms_abi__)) glMultiDrawElementsIndirect)(
            GLenum mode,
            GLenum type,
            const void *indirect,
            GLsizei drawcount,
            GLsizei stride);
        void (*__attribute__((
            __ms_abi__)) glMultiDrawElementsIndirectCount)(
            GLenum mode,
            GLenum type,
            const void *indirect,
            GLintptr drawcount,
            GLsizei maxdrawcount,
            GLsizei stride);
        void (*__attribute__((__ms_abi__)) glNamedBufferData)(
            GLuint buffer,
            GLsizeiptr size,
            const void *data,
            GLenum usage);
        void (*__attribute__((__ms_abi__)) glNamedBufferStorage)(
            GLuint buffer,
            GLsizeiptr size,
            const void *data,
            GLbitfield flags);
        void (*__attribute__((__ms_abi__)) glNamedBufferSubData)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size,
            const void *data);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferDrawBuffer)(
            GLuint framebuffer,
            GLenum buf);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferDrawBuffers)(
            GLuint framebuffer,
            GLsizei n,
            const GLenum *bufs);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferParameteri)(
            GLuint framebuffer,
            GLenum pname,
            GLint param);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferReadBuffer)(
            GLuint framebuffer,
            GLenum src);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferRenderbuffer)(
            GLuint framebuffer,
            GLenum attachment,
            GLenum renderbuffertarget,
            GLuint renderbuffer);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferTexture)(
            GLuint framebuffer,
            GLenum attachment,
            GLuint texture,
            GLint level);
        void (*__attribute__((
            __ms_abi__)) glNamedFramebufferTextureLayer)(
            GLuint framebuffer,
            GLenum attachment,
            GLuint texture,
            GLint level,
            GLint layer);
        void (*__attribute__((
            __ms_abi__)) glNamedRenderbufferStorage)(
            GLuint renderbuffer,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glNamedRenderbufferStorageMultisample)(
            GLuint renderbuffer,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glObjectLabel)(
            GLenum identifier,
            GLuint name,
            GLsizei length,
            const GLchar *label);
        void (*__attribute__((__ms_abi__)) glObjectPtrLabel)(
            const void *ptr,
            GLsizei length,
            const GLchar *label);
        void (*__attribute__((__ms_abi__)) glPatchParameterfv)(
            GLenum pname,
            const GLfloat *values);
        void (*__attribute__((__ms_abi__)) glPatchParameteri)(
            GLenum pname,
            GLint value);
        void (*__attribute__((
            __ms_abi__)) glPauseTransformFeedback)(void);
        void (*__attribute__((__ms_abi__)) glPixelStoref)(
            GLenum pname,
            GLfloat param);
        void (*__attribute__((__ms_abi__)) glPixelStorei)(
            GLenum pname,
            GLint param);
        void (*__attribute__((__ms_abi__)) glPointParameterf)(
            GLenum pname,
            GLfloat param);
        void (*__attribute__((__ms_abi__)) glPointParameterfv)(
            GLenum pname,
            const GLfloat *params);
        void (*__attribute__((__ms_abi__)) glPointParameteri)(
            GLenum pname,
            GLint param);
        void (*__attribute__((__ms_abi__)) glPointParameteriv)(
            GLenum pname,
            const GLint *params);
        void (*__attribute__((__ms_abi__)) glPointSize)(
            GLfloat size);
        void (*__attribute__((__ms_abi__)) glPolygonMode)(
            GLenum face,
            GLenum mode);
        void (*__attribute__((__ms_abi__)) glPolygonOffset)(
            GLfloat factor,
            GLfloat units);
        void (*__attribute__((__ms_abi__)) glPolygonOffsetClamp)(
            GLfloat factor,
            GLfloat units,
            GLfloat clamp);
        void (*__attribute__((__ms_abi__)) glPopDebugGroup)(
            void);
        void (*__attribute__((
            __ms_abi__)) glPrimitiveRestartIndex)(GLuint index);
        void (*__attribute__((__ms_abi__)) glProgramBinary)(
            GLuint program,
            GLenum binaryFormat,
            const void *binary,
            GLsizei length);
        void (*__attribute__((__ms_abi__)) glProgramParameteri)(
            GLuint program,
            GLenum pname,
            GLint value);
        void (*__attribute__((__ms_abi__)) glProgramUniform1d)(
            GLuint program,
            GLint location,
            GLdouble v0);
        void (*__attribute__((__ms_abi__)) glProgramUniform1dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform1f)(
            GLuint program,
            GLint location,
            GLfloat v0);
        void (*__attribute__((__ms_abi__)) glProgramUniform1fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform1i)(
            GLuint program,
            GLint location,
            GLint v0);
        void (*__attribute__((__ms_abi__)) glProgramUniform1iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform1ui)(
            GLuint program,
            GLint location,
            GLuint v0);
        void (*__attribute__((__ms_abi__)) glProgramUniform1uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform2d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1);
        void (*__attribute__((__ms_abi__)) glProgramUniform2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform2f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1);
        void (*__attribute__((__ms_abi__)) glProgramUniform2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform2i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1);
        void (*__attribute__((__ms_abi__)) glProgramUniform2iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform2ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1);
        void (*__attribute__((__ms_abi__)) glProgramUniform2uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform3d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1,
            GLdouble v2);
        void (*__attribute__((__ms_abi__)) glProgramUniform3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform3f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2);
        void (*__attribute__((__ms_abi__)) glProgramUniform3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform3i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2);
        void (*__attribute__((__ms_abi__)) glProgramUniform3iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform3ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2);
        void (*__attribute__((__ms_abi__)) glProgramUniform3uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform4d)(
            GLuint program,
            GLint location,
            GLdouble v0,
            GLdouble v1,
            GLdouble v2,
            GLdouble v3);
        void (*__attribute__((__ms_abi__)) glProgramUniform4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform4f)(
            GLuint program,
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2,
            GLfloat v3);
        void (*__attribute__((__ms_abi__)) glProgramUniform4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform4i)(
            GLuint program,
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2,
            GLint v3);
        void (*__attribute__((__ms_abi__)) glProgramUniform4iv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glProgramUniform4ui)(
            GLuint program,
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2,
            GLuint v3);
        void (*__attribute__((__ms_abi__)) glProgramUniform4uiv)(
            GLuint program,
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2x3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2x3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2x4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix2x4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3x2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3x2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3x4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix3x4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4x2dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4x2fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4x3dv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((
            __ms_abi__)) glProgramUniformMatrix4x3fv)(
            GLuint program,
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glProvokingVertex)(
            GLenum mode);
        void (*__attribute__((__ms_abi__)) glPushDebugGroup)(
            GLenum source,
            GLuint id,
            GLsizei length,
            const GLchar *message);
        void (*__attribute__((__ms_abi__)) glQueryCounter)(
            GLuint id,
            GLenum target);
        void (*__attribute__((__ms_abi__)) glReadBuffer)(
            GLenum src);
        void (*__attribute__((__ms_abi__)) glReadPixels)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            void *pixels);
        void (*__attribute__((__ms_abi__)) glReadnPixels)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            GLsizei bufSize,
            void *data);
        void (*__attribute__((
            __ms_abi__)) glReleaseShaderCompiler)(void);
        void (*__attribute__((
            __ms_abi__)) glRenderbufferStorage)(
            GLenum target,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glRenderbufferStorageMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glResumeTransformFeedback)(void);
        void (*__attribute__((__ms_abi__)) glSampleCoverage)(
            GLfloat value,
            GLboolean invert);
        void (*__attribute__((__ms_abi__)) glSampleMaski)(
            GLuint maskNumber,
            GLbitfield mask);
        void (*__attribute__((
            __ms_abi__)) glSamplerParameterIiv)(
            GLuint sampler,
            GLenum pname,
            const GLint *param);
        void (*__attribute__((
            __ms_abi__)) glSamplerParameterIuiv)(
            GLuint sampler,
            GLenum pname,
            const GLuint *param);
        void (*__attribute__((__ms_abi__)) glSamplerParameterf)(
            GLuint sampler,
            GLenum pname,
            GLfloat param);
        void (*__attribute__((__ms_abi__)) glSamplerParameterfv)(
            GLuint sampler,
            GLenum pname,
            const GLfloat *param);
        void (*__attribute__((__ms_abi__)) glSamplerParameteri)(
            GLuint sampler,
            GLenum pname,
            GLint param);
        void (*__attribute__((__ms_abi__)) glSamplerParameteriv)(
            GLuint sampler,
            GLenum pname,
            const GLint *param);
        void (*__attribute__((__ms_abi__)) glScissor)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glScissorArrayv)(
            GLuint first,
            GLsizei count,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glScissorIndexed)(
            GLuint index,
            GLint left,
            GLint bottom,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glScissorIndexedv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glShaderBinary)(
            GLsizei count,
            const GLuint *shaders,
            GLenum binaryFormat,
            const void *binary,
            GLsizei length);
        void (*__attribute__((__ms_abi__)) glShaderSource)(
            GLuint shader,
            GLsizei count,
            const GLchar *const *string,
            const GLint *length);
        void (*__attribute__((
            __ms_abi__)) glShaderStorageBlockBinding)(
            GLuint program,
            GLuint storageBlockIndex,
            GLuint storageBlockBinding);
        void (*__attribute__((__ms_abi__)) glSpecializeShader)(
            GLuint shader,
            const GLchar *pEntryPoint,
            GLuint numSpecializationConstants,
            const GLuint *pConstantIndex,
            const GLuint *pConstantValue);
        void (*__attribute__((__ms_abi__)) glStencilFunc)(
            GLenum func,
            GLint ref,
            GLuint mask);
        void (*__attribute__((
            __ms_abi__)) glStencilFuncSeparate)(
            GLenum face,
            GLenum func,
            GLint ref,
            GLuint mask);
        void (*__attribute__((__ms_abi__)) glStencilMask)(
            GLuint mask);
        void (*__attribute__((__ms_abi__))
              glStencilMaskSeparate)(GLenum face, GLuint mask);
        void (*__attribute__((__ms_abi__)) glStencilOp)(
            GLenum fail,
            GLenum zfail,
            GLenum zpass);
        void (*__attribute__((__ms_abi__)) glStencilOpSeparate)(
            GLenum face,
            GLenum sfail,
            GLenum dpfail,
            GLenum dppass);
        void (*__attribute__((__ms_abi__)) glTexBuffer)(
            GLenum target,
            GLenum internalformat,
            GLuint buffer);
        void (*__attribute__((__ms_abi__)) glTexBufferRange)(
            GLenum target,
            GLenum internalformat,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*__attribute__((__ms_abi__)) glTexImage1D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTexImage2D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLsizei height,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((
            __ms_abi__)) glTexImage2DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTexImage3D)(
            GLenum target,
            GLint level,
            GLint internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLint border,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((
            __ms_abi__)) glTexImage3DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTexParameterIiv)(
            GLenum target,
            GLenum pname,
            const GLint *params);
        void (*__attribute__((__ms_abi__)) glTexParameterIuiv)(
            GLenum target,
            GLenum pname,
            const GLuint *params);
        void (*__attribute__((__ms_abi__)) glTexParameterf)(
            GLenum target,
            GLenum pname,
            GLfloat param);
        void (*__attribute__((__ms_abi__)) glTexParameterfv)(
            GLenum target,
            GLenum pname,
            const GLfloat *params);
        void (*__attribute__((__ms_abi__)) glTexParameteri)(
            GLenum target,
            GLenum pname,
            GLint param);
        void (*__attribute__((__ms_abi__)) glTexParameteriv)(
            GLenum target,
            GLenum pname,
            const GLint *params);
        void (*__attribute__((__ms_abi__)) glTexStorage1D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width);
        void (*__attribute__((__ms_abi__)) glTexStorage2D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glTexStorage2DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTexStorage3D)(
            GLenum target,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*__attribute__((
            __ms_abi__)) glTexStorage3DMultisample)(
            GLenum target,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTexSubImage1D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTexSubImage2D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTexSubImage3D)(
            GLenum target,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTextureBarrier)(
            void);
        void (*__attribute__((__ms_abi__)) glTextureBuffer)(
            GLuint texture,
            GLenum internalformat,
            GLuint buffer);
        void (*__attribute__((__ms_abi__)) glTextureBufferRange)(
            GLuint texture,
            GLenum internalformat,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*__attribute__((
            __ms_abi__)) glTextureParameterIiv)(
            GLuint texture,
            GLenum pname,
            const GLint *params);
        void (*__attribute__((
            __ms_abi__)) glTextureParameterIuiv)(
            GLuint texture,
            GLenum pname,
            const GLuint *params);
        void (*__attribute__((__ms_abi__)) glTextureParameterf)(
            GLuint texture,
            GLenum pname,
            GLfloat param);
        void (*__attribute__((__ms_abi__)) glTextureParameterfv)(
            GLuint texture,
            GLenum pname,
            const GLfloat *param);
        void (*__attribute__((__ms_abi__)) glTextureParameteri)(
            GLuint texture,
            GLenum pname,
            GLint param);
        void (*__attribute__((__ms_abi__)) glTextureParameteriv)(
            GLuint texture,
            GLenum pname,
            const GLint *param);
        void (*__attribute__((__ms_abi__)) glTextureStorage1D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width);
        void (*__attribute__((__ms_abi__)) glTextureStorage2D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((
            __ms_abi__)) glTextureStorage2DMultisample)(
            GLuint texture,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTextureStorage3D)(
            GLuint texture,
            GLsizei levels,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth);
        void (*__attribute__((
            __ms_abi__)) glTextureStorage3DMultisample)(
            GLuint texture,
            GLsizei samples,
            GLenum internalformat,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLboolean fixedsamplelocations);
        void (*__attribute__((__ms_abi__)) glTextureSubImage1D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLsizei width,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTextureSubImage2D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLsizei width,
            GLsizei height,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTextureSubImage3D)(
            GLuint texture,
            GLint level,
            GLint xoffset,
            GLint yoffset,
            GLint zoffset,
            GLsizei width,
            GLsizei height,
            GLsizei depth,
            GLenum format,
            GLenum type,
            const void *pixels);
        void (*__attribute__((__ms_abi__)) glTextureView)(
            GLuint texture,
            GLenum target,
            GLuint origtexture,
            GLenum internalformat,
            GLuint minlevel,
            GLuint numlevels,
            GLuint minlayer,
            GLuint numlayers);
        void (*__attribute__((
            __ms_abi__)) glTransformFeedbackBufferBase)(
            GLuint xfb,
            GLuint index,
            GLuint buffer);
        void (*__attribute__((
            __ms_abi__)) glTransformFeedbackBufferRange)(
            GLuint xfb,
            GLuint index,
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr size);
        void (*__attribute__((
            __ms_abi__)) glTransformFeedbackVaryings)(
            GLuint program,
            GLsizei count,
            const GLchar *const *varyings,
            GLenum bufferMode);
        void (*__attribute__((__ms_abi__)) glUniform1d)(
            GLint location,
            GLdouble x);
        void (*__attribute__((__ms_abi__)) glUniform1dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniform1f)(
            GLint location,
            GLfloat v0);
        void (*__attribute__((__ms_abi__)) glUniform1fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glUniform1i)(GLint location, GLint v0);
        void (*__attribute__((__ms_abi__)) glUniform1iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glUniform1ui)(
            GLint location,
            GLuint v0);
        void (*__attribute__((__ms_abi__)) glUniform1uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glUniform2d)(
            GLint location,
            GLdouble x,
            GLdouble y);
        void (*__attribute__((__ms_abi__)) glUniform2dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniform2f)(
            GLint location,
            GLfloat v0,
            GLfloat v1);
        void (*__attribute__((__ms_abi__)) glUniform2fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniform2i)(
            GLint location,
            GLint v0,
            GLint v1);
        void (*__attribute__((__ms_abi__)) glUniform2iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glUniform2ui)(
            GLint location,
            GLuint v0,
            GLuint v1);
        void (*__attribute__((__ms_abi__)) glUniform2uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glUniform3d)(
            GLint location,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (*__attribute__((__ms_abi__)) glUniform3dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniform3f)(
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2);
        void (*__attribute__((__ms_abi__)) glUniform3fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniform3i)(
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2);
        void (*__attribute__((__ms_abi__)) glUniform3iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glUniform3ui)(
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2);
        void (*__attribute__((__ms_abi__)) glUniform3uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glUniform4d)(
            GLint location,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (*__attribute__((__ms_abi__)) glUniform4dv)(
            GLint location,
            GLsizei count,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniform4f)(
            GLint location,
            GLfloat v0,
            GLfloat v1,
            GLfloat v2,
            GLfloat v3);
        void (*__attribute__((__ms_abi__)) glUniform4fv)(
            GLint location,
            GLsizei count,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniform4i)(
            GLint location,
            GLint v0,
            GLint v1,
            GLint v2,
            GLint v3);
        void (*__attribute__((__ms_abi__)) glUniform4iv)(
            GLint location,
            GLsizei count,
            const GLint *value);
        void (*__attribute__((__ms_abi__)) glUniform4ui)(
            GLint location,
            GLuint v0,
            GLuint v1,
            GLuint v2,
            GLuint v3);
        void (*__attribute__((__ms_abi__)) glUniform4uiv)(
            GLint location,
            GLsizei count,
            const GLuint *value);
        void (*__attribute__((
            __ms_abi__)) glUniformBlockBinding)(
            GLuint program,
            GLuint uniformBlockIndex,
            GLuint uniformBlockBinding);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2x3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2x3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2x4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix2x4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3x2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3x2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3x4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix3x4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4x2dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4x2fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4x3dv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLdouble *value);
        void (*__attribute__((__ms_abi__)) glUniformMatrix4x3fv)(
            GLint location,
            GLsizei count,
            GLboolean transpose,
            const GLfloat *value);
        void (*__attribute__((
            __ms_abi__)) glUniformSubroutinesuiv)(
            GLenum shadertype,
            GLsizei count,
            const GLuint *indices);
        void (*__attribute__((__ms_abi__)) glUseProgram)(
            GLuint program);
        void (*__attribute__((__ms_abi__)) glUseProgramStages)(
            GLuint pipeline,
            GLbitfield stages,
            GLuint program);
        void (*__attribute__((__ms_abi__)) glValidateProgram)(
            GLuint program);
        void (*__attribute__((__ms_abi__))
              glValidateProgramPipeline)(GLuint pipeline);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayAttribBinding)(
            GLuint vaobj,
            GLuint attribindex,
            GLuint bindingindex);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayAttribFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLuint relativeoffset);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayAttribIFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayAttribLFormat)(
            GLuint vaobj,
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayBindingDivisor)(
            GLuint vaobj,
            GLuint bindingindex,
            GLuint divisor);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayElementBuffer)(
            GLuint vaobj,
            GLuint buffer);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayVertexBuffer)(
            GLuint vaobj,
            GLuint bindingindex,
            GLuint buffer,
            GLintptr offset,
            GLsizei stride);
        void (*__attribute__((
            __ms_abi__)) glVertexArrayVertexBuffers)(
            GLuint vaobj,
            GLuint first,
            GLsizei count,
            const GLuint *buffers,
            const GLintptr *offsets,
            const GLsizei *strides);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1d)(
            GLuint index,
            GLdouble x);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1f)(
            GLuint index,
            GLfloat x);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1fv)(
            GLuint index,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1s)(
            GLuint index,
            GLshort x);
        void (*__attribute__((__ms_abi__)) glVertexAttrib1sv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2d)(
            GLuint index,
            GLdouble x,
            GLdouble y);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2f)(
            GLuint index,
            GLfloat x,
            GLfloat y);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2fv)(
            GLuint index,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2s)(
            GLuint index,
            GLshort x,
            GLshort y);
        void (*__attribute__((__ms_abi__)) glVertexAttrib2sv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3f)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat z);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3fv)(
            GLuint index,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3s)(
            GLuint index,
            GLshort x,
            GLshort y,
            GLshort z);
        void (*__attribute__((__ms_abi__)) glVertexAttrib3sv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nbv)(
            GLuint index,
            const GLbyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Niv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nsv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nub)(
            GLuint index,
            GLubyte x,
            GLubyte y,
            GLubyte z,
            GLubyte w);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nubv)(
            GLuint index,
            const GLubyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nuiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4Nusv)(
            GLuint index,
            const GLushort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4bv)(
            GLuint index,
            const GLbyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4f)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat z,
            GLfloat w);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4fv)(
            GLuint index,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4iv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4s)(
            GLuint index,
            GLshort x,
            GLshort y,
            GLshort z,
            GLshort w);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4sv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4ubv)(
            GLuint index,
            const GLubyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4uiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttrib4usv)(
            GLuint index,
            const GLushort *v);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribBinding)(
            GLuint attribindex,
            GLuint bindingindex);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribDivisor)(
            GLuint index,
            GLuint divisor);
        void (*__attribute__((__ms_abi__)) glVertexAttribFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLuint relativeoffset);
        void (*__attribute__((__ms_abi__)) glVertexAttribI1i)(
            GLuint index,
            GLint x);
        void (*__attribute__((__ms_abi__)) glVertexAttribI1iv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI1ui)(
            GLuint index,
            GLuint x);
        void (*__attribute__((__ms_abi__)) glVertexAttribI1uiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI2i)(
            GLuint index,
            GLint x,
            GLint y);
        void (*__attribute__((__ms_abi__)) glVertexAttribI2iv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI2ui)(
            GLuint index,
            GLuint x,
            GLuint y);
        void (*__attribute__((__ms_abi__)) glVertexAttribI2uiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI3i)(
            GLuint index,
            GLint x,
            GLint y,
            GLint z);
        void (*__attribute__((__ms_abi__)) glVertexAttribI3iv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI3ui)(
            GLuint index,
            GLuint x,
            GLuint y,
            GLuint z);
        void (*__attribute__((__ms_abi__)) glVertexAttribI3uiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4bv)(
            GLuint index,
            const GLbyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4i)(
            GLuint index,
            GLint x,
            GLint y,
            GLint z,
            GLint w);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4iv)(
            GLuint index,
            const GLint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4sv)(
            GLuint index,
            const GLshort *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4ubv)(
            GLuint index,
            const GLubyte *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4ui)(
            GLuint index,
            GLuint x,
            GLuint y,
            GLuint z,
            GLuint w);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4uiv)(
            GLuint index,
            const GLuint *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribI4usv)(
            GLuint index,
            const GLushort *v);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribIFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribIPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLsizei stride,
            const void *pointer);
        void (*__attribute__((__ms_abi__)) glVertexAttribL1d)(
            GLuint index,
            GLdouble x);
        void (*__attribute__((__ms_abi__)) glVertexAttribL1dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribL2d)(
            GLuint index,
            GLdouble x,
            GLdouble y);
        void (*__attribute__((__ms_abi__)) glVertexAttribL2dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribL3d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z);
        void (*__attribute__((__ms_abi__)) glVertexAttribL3dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((__ms_abi__)) glVertexAttribL4d)(
            GLuint index,
            GLdouble x,
            GLdouble y,
            GLdouble z,
            GLdouble w);
        void (*__attribute__((__ms_abi__)) glVertexAttribL4dv)(
            GLuint index,
            const GLdouble *v);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribLFormat)(
            GLuint attribindex,
            GLint size,
            GLenum type,
            GLuint relativeoffset);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribLPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLsizei stride,
            const void *pointer);
        void (*__attribute__((__ms_abi__)) glVertexAttribP1ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP1uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP2ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP2uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP3ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP3uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP4ui)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            GLuint value);
        void (*__attribute__((__ms_abi__)) glVertexAttribP4uiv)(
            GLuint index,
            GLenum type,
            GLboolean normalized,
            const GLuint *value);
        void (*__attribute__((
            __ms_abi__)) glVertexAttribPointer)(
            GLuint index,
            GLint size,
            GLenum type,
            GLboolean normalized,
            GLsizei stride,
            const void *pointer);
        void (*__attribute__((
            __ms_abi__)) glVertexBindingDivisor)(
            GLuint bindingindex,
            GLuint divisor);
        void (*__attribute__((__ms_abi__)) glViewport)(
            GLint x,
            GLint y,
            GLsizei width,
            GLsizei height);
        void (*__attribute__((__ms_abi__)) glViewportArrayv)(
            GLuint first,
            GLsizei count,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glViewportIndexedf)(
            GLuint index,
            GLfloat x,
            GLfloat y,
            GLfloat w,
            GLfloat h);
        void (*__attribute__((__ms_abi__)) glViewportIndexedfv)(
            GLuint index,
            const GLfloat *v);
        void (*__attribute__((__ms_abi__)) glWaitSync)(
            GLsync sync,
            GLbitfield flags,
            GLuint64 timeout);
        void *(*__attribute__((__ms_abi__)) glMapBuffer)(
            GLenum target,
            GLenum access);
        void *(*__attribute__((__ms_abi__)) glMapBufferRange)(
            GLenum target,
            GLintptr offset,
            GLsizeiptr length,
            GLbitfield access);
        void *(*__attribute__((__ms_abi__)) glMapNamedBuffer)(
            GLuint buffer,
            GLenum access);
        void *(*__attribute__((
            __ms_abi__)) glMapNamedBufferRange)(
            GLuint buffer,
            GLintptr offset,
            GLsizeiptr length,
            GLbitfield access);
    } ms;
};

GL3W_API extern union GL3WProcs gl3wProcs;

/* OpenGL functions */
static GLboolean glIsBuffer(GLuint buffer) {
    if (IsWindows())
        return gl3wProcs.ms.glIsBuffer(buffer);
    else
        return gl3wProcs.sysv.glIsBuffer(buffer);
}

static GLboolean glIsEnabled(GLenum cap) {
    if (IsWindows())
        return gl3wProcs.ms.glIsEnabled(cap);
    else
        return gl3wProcs.sysv.glIsEnabled(cap);
}

static GLboolean glIsEnabledi(GLenum target, GLuint index) {
    if (IsWindows())
        return gl3wProcs.ms.glIsEnabledi(target, index);
    else
        return gl3wProcs.sysv.glIsEnabledi(target, index);
}

static GLboolean glIsFramebuffer(GLuint framebuffer) {
    if (IsWindows())
        return gl3wProcs.ms.glIsFramebuffer(framebuffer);
    else
        return gl3wProcs.sysv.glIsFramebuffer(framebuffer);
}

static GLboolean glIsProgram(GLuint program) {
    if (IsWindows())
        return gl3wProcs.ms.glIsProgram(program);
    else
        return gl3wProcs.sysv.glIsProgram(program);
}

static GLboolean glIsProgramPipeline(GLuint pipeline) {
    if (IsWindows())
        return gl3wProcs.ms.glIsProgramPipeline(pipeline);
    else
        return gl3wProcs.sysv.glIsProgramPipeline(pipeline);
}

static GLboolean glIsQuery(GLuint id) {
    if (IsWindows())
        return gl3wProcs.ms.glIsQuery(id);
    else
        return gl3wProcs.sysv.glIsQuery(id);
}

static GLboolean glIsRenderbuffer(GLuint renderbuffer) {
    if (IsWindows())
        return gl3wProcs.ms.glIsRenderbuffer(renderbuffer);
    else
        return gl3wProcs.sysv.glIsRenderbuffer(renderbuffer);
}

static GLboolean glIsSampler(GLuint sampler) {
    if (IsWindows())
        return gl3wProcs.ms.glIsSampler(sampler);
    else
        return gl3wProcs.sysv.glIsSampler(sampler);
}

static GLboolean glIsShader(GLuint shader) {
    if (IsWindows())
        return gl3wProcs.ms.glIsShader(shader);
    else
        return gl3wProcs.sysv.glIsShader(shader);
}

static GLboolean glIsSync(GLsync sync) {
    if (IsWindows())
        return gl3wProcs.ms.glIsSync(sync);
    else
        return gl3wProcs.sysv.glIsSync(sync);
}

static GLboolean glIsTexture(GLuint texture) {
    if (IsWindows())
        return gl3wProcs.ms.glIsTexture(texture);
    else
        return gl3wProcs.sysv.glIsTexture(texture);
}

static GLboolean glIsTransformFeedback(GLuint id) {
    if (IsWindows())
        return gl3wProcs.ms.glIsTransformFeedback(id);
    else
        return gl3wProcs.sysv.glIsTransformFeedback(id);
}

static GLboolean glIsVertexArray(GLuint array) {
    if (IsWindows())
        return gl3wProcs.ms.glIsVertexArray(array);
    else
        return gl3wProcs.sysv.glIsVertexArray(array);
}

static GLboolean glUnmapBuffer(GLenum target) {
    if (IsWindows())
        return gl3wProcs.ms.glUnmapBuffer(target);
    else
        return gl3wProcs.sysv.glUnmapBuffer(target);
}

static GLboolean glUnmapNamedBuffer(GLuint buffer) {
    if (IsWindows())
        return gl3wProcs.ms.glUnmapNamedBuffer(buffer);
    else
        return gl3wProcs.sysv.glUnmapNamedBuffer(buffer);
}

static GLenum glCheckFramebufferStatus(GLenum target) {
    if (IsWindows())
        return gl3wProcs.ms.glCheckFramebufferStatus(target);
    else
        return gl3wProcs.sysv.glCheckFramebufferStatus(target);
}

static GLenum glCheckNamedFramebufferStatus(
    GLuint framebuffer,
    GLenum target) {
    if (IsWindows())
        return gl3wProcs.ms.glCheckNamedFramebufferStatus(
            framebuffer,
            target);
    else
        return gl3wProcs.sysv.glCheckNamedFramebufferStatus(
            framebuffer,
            target);
}

static GLenum glClientWaitSync(
    GLsync sync,
    GLbitfield flags,
    GLuint64 timeout) {
    if (IsWindows())
        return gl3wProcs.ms.glClientWaitSync(
            sync,
            flags,
            timeout);
    else
        return gl3wProcs.sysv.glClientWaitSync(
            sync,
            flags,
            timeout);
}

static GLenum glGetError(void) {
    if (IsWindows())
        return gl3wProcs.ms.glGetError();
    else
        return gl3wProcs.sysv.glGetError();
}

static GLenum glGetGraphicsResetStatus(void) {
    if (IsWindows())
        return gl3wProcs.ms.glGetGraphicsResetStatus();
    else
        return gl3wProcs.sysv.glGetGraphicsResetStatus();
}

static GLint glGetAttribLocation(
    GLuint program,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetAttribLocation(program, name);
    else
        return gl3wProcs.sysv.glGetAttribLocation(program, name);
}

static GLint glGetFragDataIndex(
    GLuint program,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetFragDataIndex(program, name);
    else
        return gl3wProcs.sysv.glGetFragDataIndex(program, name);
}

static GLint glGetFragDataLocation(
    GLuint program,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetFragDataLocation(program, name);
    else
        return gl3wProcs.sysv.glGetFragDataLocation(
            program,
            name);
}

static GLint glGetProgramResourceLocation(
    GLuint program,
    GLenum programInterface,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetProgramResourceLocation(
            program,
            programInterface,
            name);
    else
        return gl3wProcs.sysv.glGetProgramResourceLocation(
            program,
            programInterface,
            name);
}

static GLint glGetProgramResourceLocationIndex(
    GLuint program,
    GLenum programInterface,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetProgramResourceLocationIndex(
            program,
            programInterface,
            name);
    else
        return gl3wProcs.sysv.glGetProgramResourceLocationIndex(
            program,
            programInterface,
            name);
}

static GLint glGetSubroutineUniformLocation(
    GLuint program,
    GLenum shadertype,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetSubroutineUniformLocation(
            program,
            shadertype,
            name);
    else
        return gl3wProcs.sysv.glGetSubroutineUniformLocation(
            program,
            shadertype,
            name);
}

static GLint glGetUniformLocation(
    GLuint program,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetUniformLocation(program, name);
    else
        return gl3wProcs.sysv.glGetUniformLocation(
            program,
            name);
}

static GLsync glFenceSync(GLenum condition, GLbitfield flags) {
    if (IsWindows())
        return gl3wProcs.ms.glFenceSync(condition, flags);
    else
        return gl3wProcs.sysv.glFenceSync(condition, flags);
}

static GLuint glCreateProgram(void) {
    if (IsWindows())
        return gl3wProcs.ms.glCreateProgram();
    else
        return gl3wProcs.sysv.glCreateProgram();
}

static GLuint glCreateShader(GLenum type) {
    if (IsWindows())
        return gl3wProcs.ms.glCreateShader(type);
    else
        return gl3wProcs.sysv.glCreateShader(type);
}

static GLuint glCreateShaderProgramv(
    GLenum type,
    GLsizei count,
    const GLchar *const *strings) {
    if (IsWindows())
        return gl3wProcs.ms.glCreateShaderProgramv(
            type,
            count,
            strings);
    else
        return gl3wProcs.sysv.glCreateShaderProgramv(
            type,
            count,
            strings);
}

static GLuint glGetDebugMessageLog(
    GLuint count,
    GLsizei bufSize,
    GLenum *sources,
    GLenum *types,
    GLuint *ids,
    GLenum *severities,
    GLsizei *lengths,
    GLchar *messageLog) {
    if (IsWindows())
        return gl3wProcs.ms.glGetDebugMessageLog(
            count,
            bufSize,
            sources,
            types,
            ids,
            severities,
            lengths,
            messageLog);
    else
        return gl3wProcs.sysv.glGetDebugMessageLog(
            count,
            bufSize,
            sources,
            types,
            ids,
            severities,
            lengths,
            messageLog);
}

static GLuint glGetProgramResourceIndex(
    GLuint program,
    GLenum programInterface,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetProgramResourceIndex(
            program,
            programInterface,
            name);
    else
        return gl3wProcs.sysv.glGetProgramResourceIndex(
            program,
            programInterface,
            name);
}

static GLuint glGetSubroutineIndex(
    GLuint program,
    GLenum shadertype,
    const GLchar *name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetSubroutineIndex(
            program,
            shadertype,
            name);
    else
        return gl3wProcs.sysv.glGetSubroutineIndex(
            program,
            shadertype,
            name);
}

static GLuint glGetUniformBlockIndex(
    GLuint program,
    const GLchar *uniformBlockName) {
    if (IsWindows())
        return gl3wProcs.ms.glGetUniformBlockIndex(
            program,
            uniformBlockName);
    else
        return gl3wProcs.sysv.glGetUniformBlockIndex(
            program,
            uniformBlockName);
}

static const GLubyte *glGetString(GLenum name) {
    if (IsWindows())
        return gl3wProcs.ms.glGetString(name);
    else
        return gl3wProcs.sysv.glGetString(name);
}

static const GLubyte *glGetStringi(GLenum name, GLuint index) {
    if (IsWindows())
        return gl3wProcs.ms.glGetStringi(name, index);
    else
        return gl3wProcs.sysv.glGetStringi(name, index);
}

static void glActiveShaderProgram(
    GLuint pipeline,
    GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glActiveShaderProgram(pipeline, program);
    else
        gl3wProcs.sysv.glActiveShaderProgram(pipeline, program);
}

static void glActiveTexture(GLenum texture) {
    if (IsWindows())
        gl3wProcs.ms.glActiveTexture(texture);
    else
        gl3wProcs.sysv.glActiveTexture(texture);
}

static void glAttachShader(GLuint program, GLuint shader) {
    if (IsWindows())
        gl3wProcs.ms.glAttachShader(program, shader);
    else
        gl3wProcs.sysv.glAttachShader(program, shader);
}

static void glBeginConditionalRender(GLuint id, GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glBeginConditionalRender(id, mode);
    else
        gl3wProcs.sysv.glBeginConditionalRender(id, mode);
}

static void glBeginQuery(GLenum target, GLuint id) {
    if (IsWindows())
        gl3wProcs.ms.glBeginQuery(target, id);
    else
        gl3wProcs.sysv.glBeginQuery(target, id);
}

static void
glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
    if (IsWindows())
        gl3wProcs.ms.glBeginQueryIndexed(target, index, id);
    else
        gl3wProcs.sysv.glBeginQueryIndexed(target, index, id);
}

static void glBeginTransformFeedback(GLenum primitiveMode) {
    if (IsWindows())
        gl3wProcs.ms.glBeginTransformFeedback(primitiveMode);
    else
        gl3wProcs.sysv.glBeginTransformFeedback(primitiveMode);
}

static void glBindAttribLocation(
    GLuint program,
    GLuint index,
    const GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glBindAttribLocation(program, index, name);
    else
        gl3wProcs.sysv.glBindAttribLocation(
            program,
            index,
            name);
}

static void glBindBuffer(GLenum target, GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glBindBuffer(target, buffer);
    else
        gl3wProcs.sysv.glBindBuffer(target, buffer);
}

static void
glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glBindBufferBase(target, index, buffer);
    else
        gl3wProcs.sysv.glBindBufferBase(target, index, buffer);
}

static void glBindBufferRange(
    GLenum target,
    GLuint index,
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glBindBufferRange(
            target,
            index,
            buffer,
            offset,
            size);
    else
        gl3wProcs.sysv.glBindBufferRange(
            target,
            index,
            buffer,
            offset,
            size);
}

static void glBindBuffersBase(
    GLenum target,
    GLuint first,
    GLsizei count,
    const GLuint *buffers) {
    if (IsWindows())
        gl3wProcs.ms
            .glBindBuffersBase(target, first, count, buffers);
    else
        gl3wProcs.sysv
            .glBindBuffersBase(target, first, count, buffers);
}

static void glBindBuffersRange(
    GLenum target,
    GLuint first,
    GLsizei count,
    const GLuint *buffers,
    const GLintptr *offsets,
    const GLsizeiptr *sizes) {
    if (IsWindows())
        gl3wProcs.ms.glBindBuffersRange(
            target,
            first,
            count,
            buffers,
            offsets,
            sizes);
    else
        gl3wProcs.sysv.glBindBuffersRange(
            target,
            first,
            count,
            buffers,
            offsets,
            sizes);
}

static void glBindFragDataLocation(
    GLuint program,
    GLuint color,
    const GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glBindFragDataLocation(
            program,
            color,
            name);
    else
        gl3wProcs.sysv.glBindFragDataLocation(
            program,
            color,
            name);
}

static void glBindFragDataLocationIndexed(
    GLuint program,
    GLuint colorNumber,
    GLuint index,
    const GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glBindFragDataLocationIndexed(
            program,
            colorNumber,
            index,
            name);
    else
        gl3wProcs.sysv.glBindFragDataLocationIndexed(
            program,
            colorNumber,
            index,
            name);
}

static void glBindFramebuffer(
    GLenum target,
    GLuint framebuffer) {
    if (IsWindows())
        gl3wProcs.ms.glBindFramebuffer(target, framebuffer);
    else
        gl3wProcs.sysv.glBindFramebuffer(target, framebuffer);
}

static void glBindImageTexture(
    GLuint unit,
    GLuint texture,
    GLint level,
    GLboolean layered,
    GLint layer,
    GLenum access,
    GLenum format) {
    if (IsWindows())
        gl3wProcs.ms.glBindImageTexture(
            unit,
            texture,
            level,
            layered,
            layer,
            access,
            format);
    else
        gl3wProcs.sysv.glBindImageTexture(
            unit,
            texture,
            level,
            layered,
            layer,
            access,
            format);
}

static void glBindImageTextures(
    GLuint first,
    GLsizei count,
    const GLuint *textures) {
    if (IsWindows())
        gl3wProcs.ms.glBindImageTextures(first, count, textures);
    else
        gl3wProcs.sysv.glBindImageTextures(
            first,
            count,
            textures);
}

static void glBindProgramPipeline(GLuint pipeline) {
    if (IsWindows())
        gl3wProcs.ms.glBindProgramPipeline(pipeline);
    else
        gl3wProcs.sysv.glBindProgramPipeline(pipeline);
}

static void glBindRenderbuffer(
    GLenum target,
    GLuint renderbuffer) {
    if (IsWindows())
        gl3wProcs.ms.glBindRenderbuffer(target, renderbuffer);
    else
        gl3wProcs.sysv.glBindRenderbuffer(target, renderbuffer);
}

static void glBindSampler(GLuint unit, GLuint sampler) {
    if (IsWindows())
        gl3wProcs.ms.glBindSampler(unit, sampler);
    else
        gl3wProcs.sysv.glBindSampler(unit, sampler);
}

static void glBindSamplers(
    GLuint first,
    GLsizei count,
    const GLuint *samplers) {
    if (IsWindows())
        gl3wProcs.ms.glBindSamplers(first, count, samplers);
    else
        gl3wProcs.sysv.glBindSamplers(first, count, samplers);
}

static void glBindTexture(GLenum target, GLuint texture) {
    if (IsWindows())
        gl3wProcs.ms.glBindTexture(target, texture);
    else
        gl3wProcs.sysv.glBindTexture(target, texture);
}

static void glBindTextureUnit(GLuint unit, GLuint texture) {
    if (IsWindows())
        gl3wProcs.ms.glBindTextureUnit(unit, texture);
    else
        gl3wProcs.sysv.glBindTextureUnit(unit, texture);
}

static void glBindTextures(
    GLuint first,
    GLsizei count,
    const GLuint *textures) {
    if (IsWindows())
        gl3wProcs.ms.glBindTextures(first, count, textures);
    else
        gl3wProcs.sysv.glBindTextures(first, count, textures);
}

static void glBindTransformFeedback(GLenum target, GLuint id) {
    if (IsWindows())
        gl3wProcs.ms.glBindTransformFeedback(target, id);
    else
        gl3wProcs.sysv.glBindTransformFeedback(target, id);
}

static void glBindVertexArray(GLuint array) {
    if (IsWindows())
        gl3wProcs.ms.glBindVertexArray(array);
    else
        gl3wProcs.sysv.glBindVertexArray(array);
}

static void glBindVertexBuffer(
    GLuint bindingindex,
    GLuint buffer,
    GLintptr offset,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glBindVertexBuffer(
            bindingindex,
            buffer,
            offset,
            stride);
    else
        gl3wProcs.sysv.glBindVertexBuffer(
            bindingindex,
            buffer,
            offset,
            stride);
}

static void glBindVertexBuffers(
    GLuint first,
    GLsizei count,
    const GLuint *buffers,
    const GLintptr *offsets,
    const GLsizei *strides) {
    if (IsWindows())
        gl3wProcs.ms.glBindVertexBuffers(
            first,
            count,
            buffers,
            offsets,
            strides);
    else
        gl3wProcs.sysv.glBindVertexBuffers(
            first,
            count,
            buffers,
            offsets,
            strides);
}

static void glBlendColor(
    GLfloat red,
    GLfloat green,
    GLfloat blue,
    GLfloat alpha) {
    if (IsWindows())
        gl3wProcs.ms.glBlendColor(red, green, blue, alpha);
    else
        gl3wProcs.sysv.glBlendColor(red, green, blue, alpha);
}

static void glBlendEquation(GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glBlendEquation(mode);
    else
        gl3wProcs.sysv.glBlendEquation(mode);
}

static void glBlendEquationSeparate(
    GLenum modeRGB,
    GLenum modeAlpha) {
    if (IsWindows())
        gl3wProcs.ms.glBlendEquationSeparate(modeRGB, modeAlpha);
    else
        gl3wProcs.sysv.glBlendEquationSeparate(
            modeRGB,
            modeAlpha);
}

static void glBlendEquationSeparatei(
    GLuint buf,
    GLenum modeRGB,
    GLenum modeAlpha) {
    if (IsWindows())
        gl3wProcs.ms.glBlendEquationSeparatei(
            buf,
            modeRGB,
            modeAlpha);
    else
        gl3wProcs.sysv.glBlendEquationSeparatei(
            buf,
            modeRGB,
            modeAlpha);
}

static void glBlendEquationi(GLuint buf, GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glBlendEquationi(buf, mode);
    else
        gl3wProcs.sysv.glBlendEquationi(buf, mode);
}

static void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    if (IsWindows())
        gl3wProcs.ms.glBlendFunc(sfactor, dfactor);
    else
        gl3wProcs.sysv.glBlendFunc(sfactor, dfactor);
}

static void glBlendFuncSeparate(
    GLenum sfactorRGB,
    GLenum dfactorRGB,
    GLenum sfactorAlpha,
    GLenum dfactorAlpha) {
    if (IsWindows())
        gl3wProcs.ms.glBlendFuncSeparate(
            sfactorRGB,
            dfactorRGB,
            sfactorAlpha,
            dfactorAlpha);
    else
        gl3wProcs.sysv.glBlendFuncSeparate(
            sfactorRGB,
            dfactorRGB,
            sfactorAlpha,
            dfactorAlpha);
}

static void glBlendFuncSeparatei(
    GLuint buf,
    GLenum srcRGB,
    GLenum dstRGB,
    GLenum srcAlpha,
    GLenum dstAlpha) {
    if (IsWindows())
        gl3wProcs.ms.glBlendFuncSeparatei(
            buf,
            srcRGB,
            dstRGB,
            srcAlpha,
            dstAlpha);
    else
        gl3wProcs.sysv.glBlendFuncSeparatei(
            buf,
            srcRGB,
            dstRGB,
            srcAlpha,
            dstAlpha);
}

static void glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
    if (IsWindows())
        gl3wProcs.ms.glBlendFunci(buf, src, dst);
    else
        gl3wProcs.sysv.glBlendFunci(buf, src, dst);
}

static void glBlitFramebuffer(
    GLint srcX0,
    GLint srcY0,
    GLint srcX1,
    GLint srcY1,
    GLint dstX0,
    GLint dstY0,
    GLint dstX1,
    GLint dstY1,
    GLbitfield mask,
    GLenum filter) {
    if (IsWindows())
        gl3wProcs.ms.glBlitFramebuffer(
            srcX0,
            srcY0,
            srcX1,
            srcY1,
            dstX0,
            dstY0,
            dstX1,
            dstY1,
            mask,
            filter);
    else
        gl3wProcs.sysv.glBlitFramebuffer(
            srcX0,
            srcY0,
            srcX1,
            srcY1,
            dstX0,
            dstY0,
            dstX1,
            dstY1,
            mask,
            filter);
}

static void glBlitNamedFramebuffer(
    GLuint readFramebuffer,
    GLuint drawFramebuffer,
    GLint srcX0,
    GLint srcY0,
    GLint srcX1,
    GLint srcY1,
    GLint dstX0,
    GLint dstY0,
    GLint dstX1,
    GLint dstY1,
    GLbitfield mask,
    GLenum filter) {
    if (IsWindows())
        gl3wProcs.ms.glBlitNamedFramebuffer(
            readFramebuffer,
            drawFramebuffer,
            srcX0,
            srcY0,
            srcX1,
            srcY1,
            dstX0,
            dstY0,
            dstX1,
            dstY1,
            mask,
            filter);
    else
        gl3wProcs.sysv.glBlitNamedFramebuffer(
            readFramebuffer,
            drawFramebuffer,
            srcX0,
            srcY0,
            srcX1,
            srcY1,
            dstX0,
            dstY0,
            dstX1,
            dstY1,
            mask,
            filter);
}

static void glBufferData(
    GLenum target,
    GLsizeiptr size,
    const void *data,
    GLenum usage) {
    if (IsWindows())
        gl3wProcs.ms.glBufferData(target, size, data, usage);
    else
        gl3wProcs.sysv.glBufferData(target, size, data, usage);
}

static void glBufferStorage(
    GLenum target,
    GLsizeiptr size,
    const void *data,
    GLbitfield flags) {
    if (IsWindows())
        gl3wProcs.ms.glBufferStorage(target, size, data, flags);
    else
        gl3wProcs.sysv
            .glBufferStorage(target, size, data, flags);
}

static void glBufferSubData(
    GLenum target,
    GLintptr offset,
    GLsizeiptr size,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glBufferSubData(target, offset, size, data);
    else
        gl3wProcs.sysv
            .glBufferSubData(target, offset, size, data);
}

static void glClampColor(GLenum target, GLenum clamp) {
    if (IsWindows())
        gl3wProcs.ms.glClampColor(target, clamp);
    else
        gl3wProcs.sysv.glClampColor(target, clamp);
}

static void glClear(GLbitfield mask) {
    if (IsWindows())
        gl3wProcs.ms.glClear(mask);
    else
        gl3wProcs.sysv.glClear(mask);
}

static void glClearBufferData(
    GLenum target,
    GLenum internalformat,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glClearBufferData(
            target,
            internalformat,
            format,
            type,
            data);
    else
        gl3wProcs.sysv.glClearBufferData(
            target,
            internalformat,
            format,
            type,
            data);
}

static void glClearBufferSubData(
    GLenum target,
    GLenum internalformat,
    GLintptr offset,
    GLsizeiptr size,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glClearBufferSubData(
            target,
            internalformat,
            offset,
            size,
            format,
            type,
            data);
    else
        gl3wProcs.sysv.glClearBufferSubData(
            target,
            internalformat,
            offset,
            size,
            format,
            type,
            data);
}

static void glClearBufferfi(
    GLenum buffer,
    GLint drawbuffer,
    GLfloat depth,
    GLint stencil) {
    if (IsWindows())
        gl3wProcs.ms
            .glClearBufferfi(buffer, drawbuffer, depth, stencil);
    else
        gl3wProcs.sysv
            .glClearBufferfi(buffer, drawbuffer, depth, stencil);
}

static void glClearBufferfv(
    GLenum buffer,
    GLint drawbuffer,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearBufferfv(buffer, drawbuffer, value);
    else
        gl3wProcs.sysv.glClearBufferfv(
            buffer,
            drawbuffer,
            value);
}

static void glClearBufferiv(
    GLenum buffer,
    GLint drawbuffer,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearBufferiv(buffer, drawbuffer, value);
    else
        gl3wProcs.sysv.glClearBufferiv(
            buffer,
            drawbuffer,
            value);
}

static void glClearBufferuiv(
    GLenum buffer,
    GLint drawbuffer,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearBufferuiv(buffer, drawbuffer, value);
    else
        gl3wProcs.sysv.glClearBufferuiv(
            buffer,
            drawbuffer,
            value);
}

static void glClearColor(
    GLfloat red,
    GLfloat green,
    GLfloat blue,
    GLfloat alpha) {
    if (IsWindows())
        gl3wProcs.ms.glClearColor(red, green, blue, alpha);
    else
        gl3wProcs.sysv.glClearColor(red, green, blue, alpha);
}

static void glClearDepth(GLdouble depth) {
    if (IsWindows())
        gl3wProcs.ms.glClearDepth(depth);
    else
        gl3wProcs.sysv.glClearDepth(depth);
}

static void glClearDepthf(GLfloat d) {
    if (IsWindows())
        gl3wProcs.ms.glClearDepthf(d);
    else
        gl3wProcs.sysv.glClearDepthf(d);
}

static void glClearNamedBufferData(
    GLuint buffer,
    GLenum internalformat,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedBufferData(
            buffer,
            internalformat,
            format,
            type,
            data);
    else
        gl3wProcs.sysv.glClearNamedBufferData(
            buffer,
            internalformat,
            format,
            type,
            data);
}

static void glClearNamedBufferSubData(
    GLuint buffer,
    GLenum internalformat,
    GLintptr offset,
    GLsizeiptr size,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedBufferSubData(
            buffer,
            internalformat,
            offset,
            size,
            format,
            type,
            data);
    else
        gl3wProcs.sysv.glClearNamedBufferSubData(
            buffer,
            internalformat,
            offset,
            size,
            format,
            type,
            data);
}

static void glClearNamedFramebufferfi(
    GLuint framebuffer,
    GLenum buffer,
    GLint drawbuffer,
    GLfloat depth,
    GLint stencil) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedFramebufferfi(
            framebuffer,
            buffer,
            drawbuffer,
            depth,
            stencil);
    else
        gl3wProcs.sysv.glClearNamedFramebufferfi(
            framebuffer,
            buffer,
            drawbuffer,
            depth,
            stencil);
}

static void glClearNamedFramebufferfv(
    GLuint framebuffer,
    GLenum buffer,
    GLint drawbuffer,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedFramebufferfv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
    else
        gl3wProcs.sysv.glClearNamedFramebufferfv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
}

static void glClearNamedFramebufferiv(
    GLuint framebuffer,
    GLenum buffer,
    GLint drawbuffer,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedFramebufferiv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
    else
        gl3wProcs.sysv.glClearNamedFramebufferiv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
}

static void glClearNamedFramebufferuiv(
    GLuint framebuffer,
    GLenum buffer,
    GLint drawbuffer,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glClearNamedFramebufferuiv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
    else
        gl3wProcs.sysv.glClearNamedFramebufferuiv(
            framebuffer,
            buffer,
            drawbuffer,
            value);
}

static void glClearStencil(GLint s) {
    if (IsWindows())
        gl3wProcs.ms.glClearStencil(s);
    else
        gl3wProcs.sysv.glClearStencil(s);
}

static void glClearTexImage(
    GLuint texture,
    GLint level,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms
            .glClearTexImage(texture, level, format, type, data);
    else
        gl3wProcs.sysv
            .glClearTexImage(texture, level, format, type, data);
}

static void glClearTexSubImage(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLenum type,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glClearTexSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            data);
    else
        gl3wProcs.sysv.glClearTexSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            data);
}

static void glClipControl(GLenum origin, GLenum depth) {
    if (IsWindows())
        gl3wProcs.ms.glClipControl(origin, depth);
    else
        gl3wProcs.sysv.glClipControl(origin, depth);
}

static void glColorMask(
    GLboolean red,
    GLboolean green,
    GLboolean blue,
    GLboolean alpha) {
    if (IsWindows())
        gl3wProcs.ms.glColorMask(red, green, blue, alpha);
    else
        gl3wProcs.sysv.glColorMask(red, green, blue, alpha);
}

static void glColorMaski(
    GLuint index,
    GLboolean r,
    GLboolean g,
    GLboolean b,
    GLboolean a) {
    if (IsWindows())
        gl3wProcs.ms.glColorMaski(index, r, g, b, a);
    else
        gl3wProcs.sysv.glColorMaski(index, r, g, b, a);
}

static void glCompileShader(GLuint shader) {
    if (IsWindows())
        gl3wProcs.ms.glCompileShader(shader);
    else
        gl3wProcs.sysv.glCompileShader(shader);
}

static void glCompressedTexImage1D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLint border,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexImage1D(
            target,
            level,
            internalformat,
            width,
            border,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexImage1D(
            target,
            level,
            internalformat,
            width,
            border,
            imageSize,
            data);
}

static void glCompressedTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexImage2D(
            target,
            level,
            internalformat,
            width,
            height,
            border,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexImage2D(
            target,
            level,
            internalformat,
            width,
            height,
            border,
            imageSize,
            data);
}

static void glCompressedTexImage3D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLint border,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexImage3D(
            target,
            level,
            internalformat,
            width,
            height,
            depth,
            border,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexImage3D(
            target,
            level,
            internalformat,
            width,
            height,
            depth,
            border,
            imageSize,
            data);
}

static void glCompressedTexSubImage1D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLsizei width,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexSubImage1D(
            target,
            level,
            xoffset,
            width,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexSubImage1D(
            target,
            level,
            xoffset,
            width,
            format,
            imageSize,
            data);
}

static void glCompressedTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            imageSize,
            data);
}

static void glCompressedTexSubImage3D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            imageSize,
            data);
}

static void glCompressedTextureSubImage1D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLsizei width,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTextureSubImage1D(
            texture,
            level,
            xoffset,
            width,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTextureSubImage1D(
            texture,
            level,
            xoffset,
            width,
            format,
            imageSize,
            data);
}

static void glCompressedTextureSubImage2D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            imageSize,
            data);
}

static void glCompressedTextureSubImage3D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLsizei imageSize,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms.glCompressedTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            imageSize,
            data);
    else
        gl3wProcs.sysv.glCompressedTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            imageSize,
            data);
}

static void glCopyBufferSubData(
    GLenum readTarget,
    GLenum writeTarget,
    GLintptr readOffset,
    GLintptr writeOffset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glCopyBufferSubData(
            readTarget,
            writeTarget,
            readOffset,
            writeOffset,
            size);
    else
        gl3wProcs.sysv.glCopyBufferSubData(
            readTarget,
            writeTarget,
            readOffset,
            writeOffset,
            size);
}

static void glCopyImageSubData(
    GLuint srcName,
    GLenum srcTarget,
    GLint srcLevel,
    GLint srcX,
    GLint srcY,
    GLint srcZ,
    GLuint dstName,
    GLenum dstTarget,
    GLint dstLevel,
    GLint dstX,
    GLint dstY,
    GLint dstZ,
    GLsizei srcWidth,
    GLsizei srcHeight,
    GLsizei srcDepth) {
    if (IsWindows())
        gl3wProcs.ms.glCopyImageSubData(
            srcName,
            srcTarget,
            srcLevel,
            srcX,
            srcY,
            srcZ,
            dstName,
            dstTarget,
            dstLevel,
            dstX,
            dstY,
            dstZ,
            srcWidth,
            srcHeight,
            srcDepth);
    else
        gl3wProcs.sysv.glCopyImageSubData(
            srcName,
            srcTarget,
            srcLevel,
            srcX,
            srcY,
            srcZ,
            dstName,
            dstTarget,
            dstLevel,
            dstX,
            dstY,
            dstZ,
            srcWidth,
            srcHeight,
            srcDepth);
}

static void glCopyNamedBufferSubData(
    GLuint readBuffer,
    GLuint writeBuffer,
    GLintptr readOffset,
    GLintptr writeOffset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glCopyNamedBufferSubData(
            readBuffer,
            writeBuffer,
            readOffset,
            writeOffset,
            size);
    else
        gl3wProcs.sysv.glCopyNamedBufferSubData(
            readBuffer,
            writeBuffer,
            readOffset,
            writeOffset,
            size);
}

static void glCopyTexImage1D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLint border) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTexImage1D(
            target,
            level,
            internalformat,
            x,
            y,
            width,
            border);
    else
        gl3wProcs.sysv.glCopyTexImage1D(
            target,
            level,
            internalformat,
            x,
            y,
            width,
            border);
}

static void glCopyTexImage2D(
    GLenum target,
    GLint level,
    GLenum internalformat,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLint border) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTexImage2D(
            target,
            level,
            internalformat,
            x,
            y,
            width,
            height,
            border);
    else
        gl3wProcs.sysv.glCopyTexImage2D(
            target,
            level,
            internalformat,
            x,
            y,
            width,
            height,
            border);
}

static void glCopyTexSubImage1D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint x,
    GLint y,
    GLsizei width) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTexSubImage1D(
            target,
            level,
            xoffset,
            x,
            y,
            width);
    else
        gl3wProcs.sysv.glCopyTexSubImage1D(
            target,
            level,
            xoffset,
            x,
            y,
            width);
}

static void glCopyTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glCopyTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            x,
            y,
            width,
            height);
}

static void glCopyTexSubImage3D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glCopyTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            x,
            y,
            width,
            height);
}

static void glCopyTextureSubImage1D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint x,
    GLint y,
    GLsizei width) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTextureSubImage1D(
            texture,
            level,
            xoffset,
            x,
            y,
            width);
    else
        gl3wProcs.sysv.glCopyTextureSubImage1D(
            texture,
            level,
            xoffset,
            x,
            y,
            width);
}

static void glCopyTextureSubImage2D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glCopyTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            x,
            y,
            width,
            height);
}

static void glCopyTextureSubImage3D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glCopyTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glCopyTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            x,
            y,
            width,
            height);
}

static void glCreateBuffers(GLsizei n, GLuint *buffers) {
    if (IsWindows())
        gl3wProcs.ms.glCreateBuffers(n, buffers);
    else
        gl3wProcs.sysv.glCreateBuffers(n, buffers);
}

static void glCreateFramebuffers(
    GLsizei n,
    GLuint *framebuffers) {
    if (IsWindows())
        gl3wProcs.ms.glCreateFramebuffers(n, framebuffers);
    else
        gl3wProcs.sysv.glCreateFramebuffers(n, framebuffers);
}

static void glCreateProgramPipelines(
    GLsizei n,
    GLuint *pipelines) {
    if (IsWindows())
        gl3wProcs.ms.glCreateProgramPipelines(n, pipelines);
    else
        gl3wProcs.sysv.glCreateProgramPipelines(n, pipelines);
}

static void
glCreateQueries(GLenum target, GLsizei n, GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glCreateQueries(target, n, ids);
    else
        gl3wProcs.sysv.glCreateQueries(target, n, ids);
}

static void glCreateRenderbuffers(
    GLsizei n,
    GLuint *renderbuffers) {
    if (IsWindows())
        gl3wProcs.ms.glCreateRenderbuffers(n, renderbuffers);
    else
        gl3wProcs.sysv.glCreateRenderbuffers(n, renderbuffers);
}

static void glCreateSamplers(GLsizei n, GLuint *samplers) {
    if (IsWindows())
        gl3wProcs.ms.glCreateSamplers(n, samplers);
    else
        gl3wProcs.sysv.glCreateSamplers(n, samplers);
}

static void
glCreateTextures(GLenum target, GLsizei n, GLuint *textures) {
    if (IsWindows())
        gl3wProcs.ms.glCreateTextures(target, n, textures);
    else
        gl3wProcs.sysv.glCreateTextures(target, n, textures);
}

static void glCreateTransformFeedbacks(GLsizei n, GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glCreateTransformFeedbacks(n, ids);
    else
        gl3wProcs.sysv.glCreateTransformFeedbacks(n, ids);
}

static void glCreateVertexArrays(GLsizei n, GLuint *arrays) {
    if (IsWindows())
        gl3wProcs.ms.glCreateVertexArrays(n, arrays);
    else
        gl3wProcs.sysv.glCreateVertexArrays(n, arrays);
}

static void glCullFace(GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glCullFace(mode);
    else
        gl3wProcs.sysv.glCullFace(mode);
}

static void glDebugMessageCallback(
    GLDEBUGPROC callback,
    const void *userParam) {
    if (IsWindows())
        gl3wProcs.ms.glDebugMessageCallback(callback, userParam);
    else
        gl3wProcs.sysv.glDebugMessageCallback(
            callback,
            userParam);
}

static void glDebugMessageControl(
    GLenum source,
    GLenum type,
    GLenum severity,
    GLsizei count,
    const GLuint *ids,
    GLboolean enabled) {
    if (IsWindows())
        gl3wProcs.ms.glDebugMessageControl(
            source,
            type,
            severity,
            count,
            ids,
            enabled);
    else
        gl3wProcs.sysv.glDebugMessageControl(
            source,
            type,
            severity,
            count,
            ids,
            enabled);
}

static void glDebugMessageInsert(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *buf) {
    if (IsWindows())
        gl3wProcs.ms.glDebugMessageInsert(
            source,
            type,
            id,
            severity,
            length,
            buf);
    else
        gl3wProcs.sysv.glDebugMessageInsert(
            source,
            type,
            id,
            severity,
            length,
            buf);
}

static void glDeleteBuffers(GLsizei n, const GLuint *buffers) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteBuffers(n, buffers);
    else
        gl3wProcs.sysv.glDeleteBuffers(n, buffers);
}

static void glDeleteFramebuffers(
    GLsizei n,
    const GLuint *framebuffers) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteFramebuffers(n, framebuffers);
    else
        gl3wProcs.sysv.glDeleteFramebuffers(n, framebuffers);
}

static void glDeleteProgram(GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteProgram(program);
    else
        gl3wProcs.sysv.glDeleteProgram(program);
}

static void glDeleteProgramPipelines(
    GLsizei n,
    const GLuint *pipelines) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteProgramPipelines(n, pipelines);
    else
        gl3wProcs.sysv.glDeleteProgramPipelines(n, pipelines);
}

static void glDeleteQueries(GLsizei n, const GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteQueries(n, ids);
    else
        gl3wProcs.sysv.glDeleteQueries(n, ids);
}

static void glDeleteRenderbuffers(
    GLsizei n,
    const GLuint *renderbuffers) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteRenderbuffers(n, renderbuffers);
    else
        gl3wProcs.sysv.glDeleteRenderbuffers(n, renderbuffers);
}

static void glDeleteSamplers(
    GLsizei count,
    const GLuint *samplers) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteSamplers(count, samplers);
    else
        gl3wProcs.sysv.glDeleteSamplers(count, samplers);
}

static void glDeleteShader(GLuint shader) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteShader(shader);
    else
        gl3wProcs.sysv.glDeleteShader(shader);
}

static void glDeleteSync(GLsync sync) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteSync(sync);
    else
        gl3wProcs.sysv.glDeleteSync(sync);
}

static void glDeleteTextures(GLsizei n, const GLuint *textures) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteTextures(n, textures);
    else
        gl3wProcs.sysv.glDeleteTextures(n, textures);
}

static void glDeleteTransformFeedbacks(
    GLsizei n,
    const GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteTransformFeedbacks(n, ids);
    else
        gl3wProcs.sysv.glDeleteTransformFeedbacks(n, ids);
}

static void glDeleteVertexArrays(
    GLsizei n,
    const GLuint *arrays) {
    if (IsWindows())
        gl3wProcs.ms.glDeleteVertexArrays(n, arrays);
    else
        gl3wProcs.sysv.glDeleteVertexArrays(n, arrays);
}

static void glDepthFunc(GLenum func) {
    if (IsWindows())
        gl3wProcs.ms.glDepthFunc(func);
    else
        gl3wProcs.sysv.glDepthFunc(func);
}

static void glDepthMask(GLboolean flag) {
    if (IsWindows())
        gl3wProcs.ms.glDepthMask(flag);
    else
        gl3wProcs.sysv.glDepthMask(flag);
}

static void glDepthRange(GLdouble n, GLdouble f) {
    if (IsWindows())
        gl3wProcs.ms.glDepthRange(n, f);
    else
        gl3wProcs.sysv.glDepthRange(n, f);
}

static void glDepthRangeArrayv(
    GLuint first,
    GLsizei count,
    const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glDepthRangeArrayv(first, count, v);
    else
        gl3wProcs.sysv.glDepthRangeArrayv(first, count, v);
}

static void
glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
    if (IsWindows())
        gl3wProcs.ms.glDepthRangeIndexed(index, n, f);
    else
        gl3wProcs.sysv.glDepthRangeIndexed(index, n, f);
}

static void glDepthRangef(GLfloat n, GLfloat f) {
    if (IsWindows())
        gl3wProcs.ms.glDepthRangef(n, f);
    else
        gl3wProcs.sysv.glDepthRangef(n, f);
}

static void glDetachShader(GLuint program, GLuint shader) {
    if (IsWindows())
        gl3wProcs.ms.glDetachShader(program, shader);
    else
        gl3wProcs.sysv.glDetachShader(program, shader);
}

static void glDisable(GLenum cap) {
    if (IsWindows())
        gl3wProcs.ms.glDisable(cap);
    else
        gl3wProcs.sysv.glDisable(cap);
}

static void glDisableVertexArrayAttrib(
    GLuint vaobj,
    GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glDisableVertexArrayAttrib(vaobj, index);
    else
        gl3wProcs.sysv.glDisableVertexArrayAttrib(vaobj, index);
}

static void glDisableVertexAttribArray(GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glDisableVertexAttribArray(index);
    else
        gl3wProcs.sysv.glDisableVertexAttribArray(index);
}

static void glDisablei(GLenum target, GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glDisablei(target, index);
    else
        gl3wProcs.sysv.glDisablei(target, index);
}

static void glDispatchCompute(
    GLuint num_groups_x,
    GLuint num_groups_y,
    GLuint num_groups_z) {
    if (IsWindows())
        gl3wProcs.ms.glDispatchCompute(
            num_groups_x,
            num_groups_y,
            num_groups_z);
    else
        gl3wProcs.sysv.glDispatchCompute(
            num_groups_x,
            num_groups_y,
            num_groups_z);
}

static void glDispatchComputeIndirect(GLintptr indirect) {
    if (IsWindows())
        gl3wProcs.ms.glDispatchComputeIndirect(indirect);
    else
        gl3wProcs.sysv.glDispatchComputeIndirect(indirect);
}

static void
glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    if (IsWindows())
        gl3wProcs.ms.glDrawArrays(mode, first, count);
    else
        gl3wProcs.sysv.glDrawArrays(mode, first, count);
}

static void glDrawArraysIndirect(
    GLenum mode,
    const void *indirect) {
    if (IsWindows())
        gl3wProcs.ms.glDrawArraysIndirect(mode, indirect);
    else
        gl3wProcs.sysv.glDrawArraysIndirect(mode, indirect);
}

static void glDrawArraysInstanced(
    GLenum mode,
    GLint first,
    GLsizei count,
    GLsizei instancecount) {
    if (IsWindows())
        gl3wProcs.ms.glDrawArraysInstanced(
            mode,
            first,
            count,
            instancecount);
    else
        gl3wProcs.sysv.glDrawArraysInstanced(
            mode,
            first,
            count,
            instancecount);
}

static void glDrawArraysInstancedBaseInstance(
    GLenum mode,
    GLint first,
    GLsizei count,
    GLsizei instancecount,
    GLuint baseinstance) {
    if (IsWindows())
        gl3wProcs.ms.glDrawArraysInstancedBaseInstance(
            mode,
            first,
            count,
            instancecount,
            baseinstance);
    else
        gl3wProcs.sysv.glDrawArraysInstancedBaseInstance(
            mode,
            first,
            count,
            instancecount,
            baseinstance);
}

static void glDrawBuffer(GLenum buf) {
    if (IsWindows())
        gl3wProcs.ms.glDrawBuffer(buf);
    else
        gl3wProcs.sysv.glDrawBuffer(buf);
}

static void glDrawBuffers(GLsizei n, const GLenum *bufs) {
    if (IsWindows())
        gl3wProcs.ms.glDrawBuffers(n, bufs);
    else
        gl3wProcs.sysv.glDrawBuffers(n, bufs);
}

static void glDrawElements(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElements(mode, count, type, indices);
    else
        gl3wProcs.sysv
            .glDrawElements(mode, count, type, indices);
}

static void glDrawElementsBaseVertex(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLint basevertex) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElementsBaseVertex(
            mode,
            count,
            type,
            indices,
            basevertex);
    else
        gl3wProcs.sysv.glDrawElementsBaseVertex(
            mode,
            count,
            type,
            indices,
            basevertex);
}

static void glDrawElementsIndirect(
    GLenum mode,
    GLenum type,
    const void *indirect) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElementsIndirect(
            mode,
            type,
            indirect);
    else
        gl3wProcs.sysv.glDrawElementsIndirect(
            mode,
            type,
            indirect);
}

static void glDrawElementsInstanced(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLsizei instancecount) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElementsInstanced(
            mode,
            count,
            type,
            indices,
            instancecount);
    else
        gl3wProcs.sysv.glDrawElementsInstanced(
            mode,
            count,
            type,
            indices,
            instancecount);
}

static void glDrawElementsInstancedBaseInstance(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLsizei instancecount,
    GLuint baseinstance) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElementsInstancedBaseInstance(
            mode,
            count,
            type,
            indices,
            instancecount,
            baseinstance);
    else
        gl3wProcs.sysv.glDrawElementsInstancedBaseInstance(
            mode,
            count,
            type,
            indices,
            instancecount,
            baseinstance);
}

static void glDrawElementsInstancedBaseVertex(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLsizei instancecount,
    GLint basevertex) {
    if (IsWindows())
        gl3wProcs.ms.glDrawElementsInstancedBaseVertex(
            mode,
            count,
            type,
            indices,
            instancecount,
            basevertex);
    else
        gl3wProcs.sysv.glDrawElementsInstancedBaseVertex(
            mode,
            count,
            type,
            indices,
            instancecount,
            basevertex);
}

static void glDrawElementsInstancedBaseVertexBaseInstance(
    GLenum mode,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLsizei instancecount,
    GLint basevertex,
    GLuint baseinstance) {
    if (IsWindows())
        gl3wProcs.ms
            .glDrawElementsInstancedBaseVertexBaseInstance(
                mode,
                count,
                type,
                indices,
                instancecount,
                basevertex,
                baseinstance);
    else
        gl3wProcs.sysv
            .glDrawElementsInstancedBaseVertexBaseInstance(
                mode,
                count,
                type,
                indices,
                instancecount,
                basevertex,
                baseinstance);
}

static void glDrawRangeElements(
    GLenum mode,
    GLuint start,
    GLuint end,
    GLsizei count,
    GLenum type,
    const void *indices) {
    if (IsWindows())
        gl3wProcs.ms.glDrawRangeElements(
            mode,
            start,
            end,
            count,
            type,
            indices);
    else
        gl3wProcs.sysv.glDrawRangeElements(
            mode,
            start,
            end,
            count,
            type,
            indices);
}

static void glDrawRangeElementsBaseVertex(
    GLenum mode,
    GLuint start,
    GLuint end,
    GLsizei count,
    GLenum type,
    const void *indices,
    GLint basevertex) {
    if (IsWindows())
        gl3wProcs.ms.glDrawRangeElementsBaseVertex(
            mode,
            start,
            end,
            count,
            type,
            indices,
            basevertex);
    else
        gl3wProcs.sysv.glDrawRangeElementsBaseVertex(
            mode,
            start,
            end,
            count,
            type,
            indices,
            basevertex);
}

static void glDrawTransformFeedback(GLenum mode, GLuint id) {
    if (IsWindows())
        gl3wProcs.ms.glDrawTransformFeedback(mode, id);
    else
        gl3wProcs.sysv.glDrawTransformFeedback(mode, id);
}

static void glDrawTransformFeedbackInstanced(
    GLenum mode,
    GLuint id,
    GLsizei instancecount) {
    if (IsWindows())
        gl3wProcs.ms.glDrawTransformFeedbackInstanced(
            mode,
            id,
            instancecount);
    else
        gl3wProcs.sysv.glDrawTransformFeedbackInstanced(
            mode,
            id,
            instancecount);
}

static void glDrawTransformFeedbackStream(
    GLenum mode,
    GLuint id,
    GLuint stream) {
    if (IsWindows())
        gl3wProcs.ms.glDrawTransformFeedbackStream(
            mode,
            id,
            stream);
    else
        gl3wProcs.sysv.glDrawTransformFeedbackStream(
            mode,
            id,
            stream);
}

static void glDrawTransformFeedbackStreamInstanced(
    GLenum mode,
    GLuint id,
    GLuint stream,
    GLsizei instancecount) {
    if (IsWindows())
        gl3wProcs.ms.glDrawTransformFeedbackStreamInstanced(
            mode,
            id,
            stream,
            instancecount);
    else
        gl3wProcs.sysv.glDrawTransformFeedbackStreamInstanced(
            mode,
            id,
            stream,
            instancecount);
}

static void glEnable(GLenum cap) {
    if (IsWindows())
        gl3wProcs.ms.glEnable(cap);
    else
        gl3wProcs.sysv.glEnable(cap);
}

static void glEnableVertexArrayAttrib(
    GLuint vaobj,
    GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glEnableVertexArrayAttrib(vaobj, index);
    else
        gl3wProcs.sysv.glEnableVertexArrayAttrib(vaobj, index);
}

static void glEnableVertexAttribArray(GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glEnableVertexAttribArray(index);
    else
        gl3wProcs.sysv.glEnableVertexAttribArray(index);
}

static void glEnablei(GLenum target, GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glEnablei(target, index);
    else
        gl3wProcs.sysv.glEnablei(target, index);
}

static void glEndConditionalRender(void) {
    if (IsWindows())
        gl3wProcs.ms.glEndConditionalRender();
    else
        gl3wProcs.sysv.glEndConditionalRender();
}

static void glEndQuery(GLenum target) {
    if (IsWindows())
        gl3wProcs.ms.glEndQuery(target);
    else
        gl3wProcs.sysv.glEndQuery(target);
}

static void glEndQueryIndexed(GLenum target, GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glEndQueryIndexed(target, index);
    else
        gl3wProcs.sysv.glEndQueryIndexed(target, index);
}

static void glEndTransformFeedback(void) {
    if (IsWindows())
        gl3wProcs.ms.glEndTransformFeedback();
    else
        gl3wProcs.sysv.glEndTransformFeedback();
}

static void glFinish(void) {
    if (IsWindows())
        gl3wProcs.ms.glFinish();
    else
        gl3wProcs.sysv.glFinish();
}

static void glFlush(void) {
    if (IsWindows())
        gl3wProcs.ms.glFlush();
    else
        gl3wProcs.sysv.glFlush();
}

static void glFlushMappedBufferRange(
    GLenum target,
    GLintptr offset,
    GLsizeiptr length) {
    if (IsWindows())
        gl3wProcs.ms.glFlushMappedBufferRange(
            target,
            offset,
            length);
    else
        gl3wProcs.sysv.glFlushMappedBufferRange(
            target,
            offset,
            length);
}

static void glFlushMappedNamedBufferRange(
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr length) {
    if (IsWindows())
        gl3wProcs.ms.glFlushMappedNamedBufferRange(
            buffer,
            offset,
            length);
    else
        gl3wProcs.sysv.glFlushMappedNamedBufferRange(
            buffer,
            offset,
            length);
}

static void glFramebufferParameteri(
    GLenum target,
    GLenum pname,
    GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferParameteri(
            target,
            pname,
            param);
    else
        gl3wProcs.sysv.glFramebufferParameteri(
            target,
            pname,
            param);
}

static void glFramebufferParameteriMESA(
    GLenum target,
    GLenum pname,
    GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferParameteriMESA(
            target,
            pname,
            param);
    else
        gl3wProcs.sysv.glFramebufferParameteriMESA(
            target,
            pname,
            param);
}

static void glFramebufferRenderbuffer(
    GLenum target,
    GLenum attachment,
    GLenum renderbuffertarget,
    GLuint renderbuffer) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferRenderbuffer(
            target,
            attachment,
            renderbuffertarget,
            renderbuffer);
    else
        gl3wProcs.sysv.glFramebufferRenderbuffer(
            target,
            attachment,
            renderbuffertarget,
            renderbuffer);
}

static void glFramebufferTexture(
    GLenum target,
    GLenum attachment,
    GLuint texture,
    GLint level) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferTexture(
            target,
            attachment,
            texture,
            level);
    else
        gl3wProcs.sysv.glFramebufferTexture(
            target,
            attachment,
            texture,
            level);
}

static void glFramebufferTexture1D(
    GLenum target,
    GLenum attachment,
    GLenum textarget,
    GLuint texture,
    GLint level) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferTexture1D(
            target,
            attachment,
            textarget,
            texture,
            level);
    else
        gl3wProcs.sysv.glFramebufferTexture1D(
            target,
            attachment,
            textarget,
            texture,
            level);
}

static void glFramebufferTexture2D(
    GLenum target,
    GLenum attachment,
    GLenum textarget,
    GLuint texture,
    GLint level) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferTexture2D(
            target,
            attachment,
            textarget,
            texture,
            level);
    else
        gl3wProcs.sysv.glFramebufferTexture2D(
            target,
            attachment,
            textarget,
            texture,
            level);
}

static void glFramebufferTexture3D(
    GLenum target,
    GLenum attachment,
    GLenum textarget,
    GLuint texture,
    GLint level,
    GLint zoffset) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferTexture3D(
            target,
            attachment,
            textarget,
            texture,
            level,
            zoffset);
    else
        gl3wProcs.sysv.glFramebufferTexture3D(
            target,
            attachment,
            textarget,
            texture,
            level,
            zoffset);
}

static void glFramebufferTextureLayer(
    GLenum target,
    GLenum attachment,
    GLuint texture,
    GLint level,
    GLint layer) {
    if (IsWindows())
        gl3wProcs.ms.glFramebufferTextureLayer(
            target,
            attachment,
            texture,
            level,
            layer);
    else
        gl3wProcs.sysv.glFramebufferTextureLayer(
            target,
            attachment,
            texture,
            level,
            layer);
}

static void glFrontFace(GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glFrontFace(mode);
    else
        gl3wProcs.sysv.glFrontFace(mode);
}

static void glGenBuffers(GLsizei n, GLuint *buffers) {
    if (IsWindows())
        gl3wProcs.ms.glGenBuffers(n, buffers);
    else
        gl3wProcs.sysv.glGenBuffers(n, buffers);
}

static void glGenFramebuffers(GLsizei n, GLuint *framebuffers) {
    if (IsWindows())
        gl3wProcs.ms.glGenFramebuffers(n, framebuffers);
    else
        gl3wProcs.sysv.glGenFramebuffers(n, framebuffers);
}

static void glGenProgramPipelines(GLsizei n, GLuint *pipelines) {
    if (IsWindows())
        gl3wProcs.ms.glGenProgramPipelines(n, pipelines);
    else
        gl3wProcs.sysv.glGenProgramPipelines(n, pipelines);
}

static void glGenQueries(GLsizei n, GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glGenQueries(n, ids);
    else
        gl3wProcs.sysv.glGenQueries(n, ids);
}

static void glGenRenderbuffers(
    GLsizei n,
    GLuint *renderbuffers) {
    if (IsWindows())
        gl3wProcs.ms.glGenRenderbuffers(n, renderbuffers);
    else
        gl3wProcs.sysv.glGenRenderbuffers(n, renderbuffers);
}

static void glGenSamplers(GLsizei count, GLuint *samplers) {
    if (IsWindows())
        gl3wProcs.ms.glGenSamplers(count, samplers);
    else
        gl3wProcs.sysv.glGenSamplers(count, samplers);
}

static void glGenTextures(GLsizei n, GLuint *textures) {
    if (IsWindows())
        gl3wProcs.ms.glGenTextures(n, textures);
    else
        gl3wProcs.sysv.glGenTextures(n, textures);
}

static void glGenTransformFeedbacks(GLsizei n, GLuint *ids) {
    if (IsWindows())
        gl3wProcs.ms.glGenTransformFeedbacks(n, ids);
    else
        gl3wProcs.sysv.glGenTransformFeedbacks(n, ids);
}

static void glGenVertexArrays(GLsizei n, GLuint *arrays) {
    if (IsWindows())
        gl3wProcs.ms.glGenVertexArrays(n, arrays);
    else
        gl3wProcs.sysv.glGenVertexArrays(n, arrays);
}

static void glGenerateMipmap(GLenum target) {
    if (IsWindows())
        gl3wProcs.ms.glGenerateMipmap(target);
    else
        gl3wProcs.sysv.glGenerateMipmap(target);
}

static void glGenerateTextureMipmap(GLuint texture) {
    if (IsWindows())
        gl3wProcs.ms.glGenerateTextureMipmap(texture);
    else
        gl3wProcs.sysv.glGenerateTextureMipmap(texture);
}

static void glGetActiveAtomicCounterBufferiv(
    GLuint program,
    GLuint bufferIndex,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveAtomicCounterBufferiv(
            program,
            bufferIndex,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetActiveAtomicCounterBufferiv(
            program,
            bufferIndex,
            pname,
            params);
}

static void glGetActiveAttrib(
    GLuint program,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLint *size,
    GLenum *type,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveAttrib(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
    else
        gl3wProcs.sysv.glGetActiveAttrib(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
}

static void glGetActiveSubroutineName(
    GLuint program,
    GLenum shadertype,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveSubroutineName(
            program,
            shadertype,
            index,
            bufSize,
            length,
            name);
    else
        gl3wProcs.sysv.glGetActiveSubroutineName(
            program,
            shadertype,
            index,
            bufSize,
            length,
            name);
}

static void glGetActiveSubroutineUniformName(
    GLuint program,
    GLenum shadertype,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveSubroutineUniformName(
            program,
            shadertype,
            index,
            bufSize,
            length,
            name);
    else
        gl3wProcs.sysv.glGetActiveSubroutineUniformName(
            program,
            shadertype,
            index,
            bufSize,
            length,
            name);
}

static void glGetActiveSubroutineUniformiv(
    GLuint program,
    GLenum shadertype,
    GLuint index,
    GLenum pname,
    GLint *values) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveSubroutineUniformiv(
            program,
            shadertype,
            index,
            pname,
            values);
    else
        gl3wProcs.sysv.glGetActiveSubroutineUniformiv(
            program,
            shadertype,
            index,
            pname,
            values);
}

static void glGetActiveUniform(
    GLuint program,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLint *size,
    GLenum *type,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveUniform(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
    else
        gl3wProcs.sysv.glGetActiveUniform(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
}

static void glGetActiveUniformBlockName(
    GLuint program,
    GLuint uniformBlockIndex,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *uniformBlockName) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveUniformBlockName(
            program,
            uniformBlockIndex,
            bufSize,
            length,
            uniformBlockName);
    else
        gl3wProcs.sysv.glGetActiveUniformBlockName(
            program,
            uniformBlockIndex,
            bufSize,
            length,
            uniformBlockName);
}

static void glGetActiveUniformBlockiv(
    GLuint program,
    GLuint uniformBlockIndex,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveUniformBlockiv(
            program,
            uniformBlockIndex,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetActiveUniformBlockiv(
            program,
            uniformBlockIndex,
            pname,
            params);
}

static void glGetActiveUniformName(
    GLuint program,
    GLuint uniformIndex,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *uniformName) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveUniformName(
            program,
            uniformIndex,
            bufSize,
            length,
            uniformName);
    else
        gl3wProcs.sysv.glGetActiveUniformName(
            program,
            uniformIndex,
            bufSize,
            length,
            uniformName);
}

static void glGetActiveUniformsiv(
    GLuint program,
    GLsizei uniformCount,
    const GLuint *uniformIndices,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetActiveUniformsiv(
            program,
            uniformCount,
            uniformIndices,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetActiveUniformsiv(
            program,
            uniformCount,
            uniformIndices,
            pname,
            params);
}

static void glGetAttachedShaders(
    GLuint program,
    GLsizei maxCount,
    GLsizei *count,
    GLuint *shaders) {
    if (IsWindows())
        gl3wProcs.ms.glGetAttachedShaders(
            program,
            maxCount,
            count,
            shaders);
    else
        gl3wProcs.sysv.glGetAttachedShaders(
            program,
            maxCount,
            count,
            shaders);
}

static void
glGetBooleani_v(GLenum target, GLuint index, GLboolean *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetBooleani_v(target, index, data);
    else
        gl3wProcs.sysv.glGetBooleani_v(target, index, data);
}

static void glGetBooleanv(GLenum pname, GLboolean *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetBooleanv(pname, data);
    else
        gl3wProcs.sysv.glGetBooleanv(pname, data);
}

static void glGetBufferParameteri64v(
    GLenum target,
    GLenum pname,
    GLint64 *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetBufferParameteri64v(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetBufferParameteri64v(
            target,
            pname,
            params);
}

static void glGetBufferParameteriv(
    GLenum target,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetBufferParameteriv(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetBufferParameteriv(
            target,
            pname,
            params);
}

static void
glGetBufferPointerv(GLenum target, GLenum pname, void **params) {
    if (IsWindows())
        gl3wProcs.ms.glGetBufferPointerv(target, pname, params);
    else
        gl3wProcs.sysv.glGetBufferPointerv(
            target,
            pname,
            params);
}

static void glGetBufferSubData(
    GLenum target,
    GLintptr offset,
    GLsizeiptr size,
    void *data) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetBufferSubData(target, offset, size, data);
    else
        gl3wProcs.sysv
            .glGetBufferSubData(target, offset, size, data);
}

static void
glGetCompressedTexImage(GLenum target, GLint level, void *img) {
    if (IsWindows())
        gl3wProcs.ms.glGetCompressedTexImage(target, level, img);
    else
        gl3wProcs.sysv.glGetCompressedTexImage(
            target,
            level,
            img);
}

static void glGetCompressedTextureImage(
    GLuint texture,
    GLint level,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetCompressedTextureImage(
            texture,
            level,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetCompressedTextureImage(
            texture,
            level,
            bufSize,
            pixels);
}

static void glGetCompressedTextureSubImage(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetCompressedTextureSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetCompressedTextureSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            bufSize,
            pixels);
}

static void
glGetDoublei_v(GLenum target, GLuint index, GLdouble *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetDoublei_v(target, index, data);
    else
        gl3wProcs.sysv.glGetDoublei_v(target, index, data);
}

static void glGetDoublev(GLenum pname, GLdouble *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetDoublev(pname, data);
    else
        gl3wProcs.sysv.glGetDoublev(pname, data);
}

static void
glGetFloati_v(GLenum target, GLuint index, GLfloat *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetFloati_v(target, index, data);
    else
        gl3wProcs.sysv.glGetFloati_v(target, index, data);
}

static void glGetFloatv(GLenum pname, GLfloat *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetFloatv(pname, data);
    else
        gl3wProcs.sysv.glGetFloatv(pname, data);
}

static void glGetFramebufferAttachmentParameteriv(
    GLenum target,
    GLenum attachment,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetFramebufferAttachmentParameteriv(
            target,
            attachment,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetFramebufferAttachmentParameteriv(
            target,
            attachment,
            pname,
            params);
}

static void glGetFramebufferParameteriv(
    GLenum target,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetFramebufferParameteriv(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetFramebufferParameteriv(
            target,
            pname,
            params);
}

static void glGetFramebufferParameterivMESA(
    GLenum target,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetFramebufferParameterivMESA(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetFramebufferParameterivMESA(
            target,
            pname,
            params);
}

static void
glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetInteger64i_v(target, index, data);
    else
        gl3wProcs.sysv.glGetInteger64i_v(target, index, data);
}

static void glGetInteger64v(GLenum pname, GLint64 *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetInteger64v(pname, data);
    else
        gl3wProcs.sysv.glGetInteger64v(pname, data);
}

static void
glGetIntegeri_v(GLenum target, GLuint index, GLint *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetIntegeri_v(target, index, data);
    else
        gl3wProcs.sysv.glGetIntegeri_v(target, index, data);
}

static void glGetIntegerv(GLenum pname, GLint *data) {
    if (IsWindows())
        gl3wProcs.ms.glGetIntegerv(pname, data);
    else
        gl3wProcs.sysv.glGetIntegerv(pname, data);
}

static void glGetInternalformati64v(
    GLenum target,
    GLenum internalformat,
    GLenum pname,
    GLsizei count,
    GLint64 *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetInternalformati64v(
            target,
            internalformat,
            pname,
            count,
            params);
    else
        gl3wProcs.sysv.glGetInternalformati64v(
            target,
            internalformat,
            pname,
            count,
            params);
}

static void glGetInternalformativ(
    GLenum target,
    GLenum internalformat,
    GLenum pname,
    GLsizei count,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetInternalformativ(
            target,
            internalformat,
            pname,
            count,
            params);
    else
        gl3wProcs.sysv.glGetInternalformativ(
            target,
            internalformat,
            pname,
            count,
            params);
}

static void
glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val) {
    if (IsWindows())
        gl3wProcs.ms.glGetMultisamplefv(pname, index, val);
    else
        gl3wProcs.sysv.glGetMultisamplefv(pname, index, val);
}

static void glGetNamedBufferParameteri64v(
    GLuint buffer,
    GLenum pname,
    GLint64 *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedBufferParameteri64v(
            buffer,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetNamedBufferParameteri64v(
            buffer,
            pname,
            params);
}

static void glGetNamedBufferParameteriv(
    GLuint buffer,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedBufferParameteriv(
            buffer,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetNamedBufferParameteriv(
            buffer,
            pname,
            params);
}

static void glGetNamedBufferPointerv(
    GLuint buffer,
    GLenum pname,
    void **params) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedBufferPointerv(
            buffer,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetNamedBufferPointerv(
            buffer,
            pname,
            params);
}

static void glGetNamedBufferSubData(
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size,
    void *data) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetNamedBufferSubData(buffer, offset, size, data);
    else
        gl3wProcs.sysv
            .glGetNamedBufferSubData(buffer, offset, size, data);
}

static void glGetNamedFramebufferAttachmentParameteriv(
    GLuint framebuffer,
    GLenum attachment,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedFramebufferAttachmentParameteriv(
            framebuffer,
            attachment,
            pname,
            params);
    else
        gl3wProcs.sysv
            .glGetNamedFramebufferAttachmentParameteriv(
                framebuffer,
                attachment,
                pname,
                params);
}

static void glGetNamedFramebufferParameteriv(
    GLuint framebuffer,
    GLenum pname,
    GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedFramebufferParameteriv(
            framebuffer,
            pname,
            param);
    else
        gl3wProcs.sysv.glGetNamedFramebufferParameteriv(
            framebuffer,
            pname,
            param);
}

static void glGetNamedRenderbufferParameteriv(
    GLuint renderbuffer,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetNamedRenderbufferParameteriv(
            renderbuffer,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetNamedRenderbufferParameteriv(
            renderbuffer,
            pname,
            params);
}

static void glGetObjectLabel(
    GLenum identifier,
    GLuint name,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *label) {
    if (IsWindows())
        gl3wProcs.ms.glGetObjectLabel(
            identifier,
            name,
            bufSize,
            length,
            label);
    else
        gl3wProcs.sysv.glGetObjectLabel(
            identifier,
            name,
            bufSize,
            length,
            label);
}

static void glGetObjectPtrLabel(
    const void *ptr,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *label) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetObjectPtrLabel(ptr, bufSize, length, label);
    else
        gl3wProcs.sysv
            .glGetObjectPtrLabel(ptr, bufSize, length, label);
}

static void glGetPointerv(GLenum pname, void **params) {
    if (IsWindows())
        gl3wProcs.ms.glGetPointerv(pname, params);
    else
        gl3wProcs.sysv.glGetPointerv(pname, params);
}

static void glGetProgramBinary(
    GLuint program,
    GLsizei bufSize,
    GLsizei *length,
    GLenum *binaryFormat,
    void *binary) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramBinary(
            program,
            bufSize,
            length,
            binaryFormat,
            binary);
    else
        gl3wProcs.sysv.glGetProgramBinary(
            program,
            bufSize,
            length,
            binaryFormat,
            binary);
}

static void glGetProgramInfoLog(
    GLuint program,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *infoLog) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramInfoLog(
            program,
            bufSize,
            length,
            infoLog);
    else
        gl3wProcs.sysv.glGetProgramInfoLog(
            program,
            bufSize,
            length,
            infoLog);
}

static void glGetProgramInterfaceiv(
    GLuint program,
    GLenum programInterface,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramInterfaceiv(
            program,
            programInterface,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetProgramInterfaceiv(
            program,
            programInterface,
            pname,
            params);
}

static void glGetProgramPipelineInfoLog(
    GLuint pipeline,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *infoLog) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramPipelineInfoLog(
            pipeline,
            bufSize,
            length,
            infoLog);
    else
        gl3wProcs.sysv.glGetProgramPipelineInfoLog(
            pipeline,
            bufSize,
            length,
            infoLog);
}

static void glGetProgramPipelineiv(
    GLuint pipeline,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramPipelineiv(
            pipeline,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetProgramPipelineiv(
            pipeline,
            pname,
            params);
}

static void glGetProgramResourceName(
    GLuint program,
    GLenum programInterface,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramResourceName(
            program,
            programInterface,
            index,
            bufSize,
            length,
            name);
    else
        gl3wProcs.sysv.glGetProgramResourceName(
            program,
            programInterface,
            index,
            bufSize,
            length,
            name);
}

static void glGetProgramResourceiv(
    GLuint program,
    GLenum programInterface,
    GLuint index,
    GLsizei propCount,
    const GLenum *props,
    GLsizei count,
    GLsizei *length,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramResourceiv(
            program,
            programInterface,
            index,
            propCount,
            props,
            count,
            length,
            params);
    else
        gl3wProcs.sysv.glGetProgramResourceiv(
            program,
            programInterface,
            index,
            propCount,
            props,
            count,
            length,
            params);
}

static void glGetProgramStageiv(
    GLuint program,
    GLenum shadertype,
    GLenum pname,
    GLint *values) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramStageiv(
            program,
            shadertype,
            pname,
            values);
    else
        gl3wProcs.sysv.glGetProgramStageiv(
            program,
            shadertype,
            pname,
            values);
}

static void
glGetProgramiv(GLuint program, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetProgramiv(program, pname, params);
    else
        gl3wProcs.sysv.glGetProgramiv(program, pname, params);
}

static void glGetQueryBufferObjecti64v(
    GLuint id,
    GLuint buffer,
    GLenum pname,
    GLintptr offset) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryBufferObjecti64v(
            id,
            buffer,
            pname,
            offset);
    else
        gl3wProcs.sysv.glGetQueryBufferObjecti64v(
            id,
            buffer,
            pname,
            offset);
}

static void glGetQueryBufferObjectiv(
    GLuint id,
    GLuint buffer,
    GLenum pname,
    GLintptr offset) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetQueryBufferObjectiv(id, buffer, pname, offset);
    else
        gl3wProcs.sysv
            .glGetQueryBufferObjectiv(id, buffer, pname, offset);
}

static void glGetQueryBufferObjectui64v(
    GLuint id,
    GLuint buffer,
    GLenum pname,
    GLintptr offset) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryBufferObjectui64v(
            id,
            buffer,
            pname,
            offset);
    else
        gl3wProcs.sysv.glGetQueryBufferObjectui64v(
            id,
            buffer,
            pname,
            offset);
}

static void glGetQueryBufferObjectuiv(
    GLuint id,
    GLuint buffer,
    GLenum pname,
    GLintptr offset) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryBufferObjectuiv(
            id,
            buffer,
            pname,
            offset);
    else
        gl3wProcs.sysv.glGetQueryBufferObjectuiv(
            id,
            buffer,
            pname,
            offset);
}

static void glGetQueryIndexediv(
    GLenum target,
    GLuint index,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetQueryIndexediv(target, index, pname, params);
    else
        gl3wProcs.sysv
            .glGetQueryIndexediv(target, index, pname, params);
}

static void
glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryObjecti64v(id, pname, params);
    else
        gl3wProcs.sysv.glGetQueryObjecti64v(id, pname, params);
}

static void
glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryObjectiv(id, pname, params);
    else
        gl3wProcs.sysv.glGetQueryObjectiv(id, pname, params);
}

static void glGetQueryObjectui64v(
    GLuint id,
    GLenum pname,
    GLuint64 *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryObjectui64v(id, pname, params);
    else
        gl3wProcs.sysv.glGetQueryObjectui64v(id, pname, params);
}

static void
glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryObjectuiv(id, pname, params);
    else
        gl3wProcs.sysv.glGetQueryObjectuiv(id, pname, params);
}

static void
glGetQueryiv(GLenum target, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetQueryiv(target, pname, params);
    else
        gl3wProcs.sysv.glGetQueryiv(target, pname, params);
}

static void glGetRenderbufferParameteriv(
    GLenum target,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetRenderbufferParameteriv(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetRenderbufferParameteriv(
            target,
            pname,
            params);
}

static void glGetSamplerParameterIiv(
    GLuint sampler,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetSamplerParameterIiv(
            sampler,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetSamplerParameterIiv(
            sampler,
            pname,
            params);
}

static void glGetSamplerParameterIuiv(
    GLuint sampler,
    GLenum pname,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetSamplerParameterIuiv(
            sampler,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetSamplerParameterIuiv(
            sampler,
            pname,
            params);
}

static void glGetSamplerParameterfv(
    GLuint sampler,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetSamplerParameterfv(
            sampler,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetSamplerParameterfv(
            sampler,
            pname,
            params);
}

static void glGetSamplerParameteriv(
    GLuint sampler,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetSamplerParameteriv(
            sampler,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetSamplerParameteriv(
            sampler,
            pname,
            params);
}

static void glGetShaderInfoLog(
    GLuint shader,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *infoLog) {
    if (IsWindows())
        gl3wProcs.ms.glGetShaderInfoLog(
            shader,
            bufSize,
            length,
            infoLog);
    else
        gl3wProcs.sysv.glGetShaderInfoLog(
            shader,
            bufSize,
            length,
            infoLog);
}

static void glGetShaderPrecisionFormat(
    GLenum shadertype,
    GLenum precisiontype,
    GLint *range,
    GLint *precision) {
    if (IsWindows())
        gl3wProcs.ms.glGetShaderPrecisionFormat(
            shadertype,
            precisiontype,
            range,
            precision);
    else
        gl3wProcs.sysv.glGetShaderPrecisionFormat(
            shadertype,
            precisiontype,
            range,
            precision);
}

static void glGetShaderSource(
    GLuint shader,
    GLsizei bufSize,
    GLsizei *length,
    GLchar *source) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetShaderSource(shader, bufSize, length, source);
    else
        gl3wProcs.sysv
            .glGetShaderSource(shader, bufSize, length, source);
}

static void
glGetShaderiv(GLuint shader, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetShaderiv(shader, pname, params);
    else
        gl3wProcs.sysv.glGetShaderiv(shader, pname, params);
}

static void glGetSynciv(
    GLsync sync,
    GLenum pname,
    GLsizei count,
    GLsizei *length,
    GLint *values) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetSynciv(sync, pname, count, length, values);
    else
        gl3wProcs.sysv
            .glGetSynciv(sync, pname, count, length, values);
}

static void glGetTexImage(
    GLenum target,
    GLint level,
    GLenum format,
    GLenum type,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetTexImage(target, level, format, type, pixels);
    else
        gl3wProcs.sysv
            .glGetTexImage(target, level, format, type, pixels);
}

static void glGetTexLevelParameterfv(
    GLenum target,
    GLint level,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexLevelParameterfv(
            target,
            level,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTexLevelParameterfv(
            target,
            level,
            pname,
            params);
}

static void glGetTexLevelParameteriv(
    GLenum target,
    GLint level,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexLevelParameteriv(
            target,
            level,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTexLevelParameteriv(
            target,
            level,
            pname,
            params);
}

static void glGetTexParameterIiv(
    GLenum target,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexParameterIiv(target, pname, params);
    else
        gl3wProcs.sysv.glGetTexParameterIiv(
            target,
            pname,
            params);
}

static void glGetTexParameterIuiv(
    GLenum target,
    GLenum pname,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexParameterIuiv(
            target,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTexParameterIuiv(
            target,
            pname,
            params);
}

static void glGetTexParameterfv(
    GLenum target,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexParameterfv(target, pname, params);
    else
        gl3wProcs.sysv.glGetTexParameterfv(
            target,
            pname,
            params);
}

static void
glGetTexParameteriv(GLenum target, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTexParameteriv(target, pname, params);
    else
        gl3wProcs.sysv.glGetTexParameteriv(
            target,
            pname,
            params);
}

static void glGetTextureImage(
    GLuint texture,
    GLint level,
    GLenum format,
    GLenum type,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureImage(
            texture,
            level,
            format,
            type,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetTextureImage(
            texture,
            level,
            format,
            type,
            bufSize,
            pixels);
}

static void glGetTextureLevelParameterfv(
    GLuint texture,
    GLint level,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureLevelParameterfv(
            texture,
            level,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureLevelParameterfv(
            texture,
            level,
            pname,
            params);
}

static void glGetTextureLevelParameteriv(
    GLuint texture,
    GLint level,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureLevelParameteriv(
            texture,
            level,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureLevelParameteriv(
            texture,
            level,
            pname,
            params);
}

static void glGetTextureParameterIiv(
    GLuint texture,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureParameterIiv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureParameterIiv(
            texture,
            pname,
            params);
}

static void glGetTextureParameterIuiv(
    GLuint texture,
    GLenum pname,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureParameterIuiv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureParameterIuiv(
            texture,
            pname,
            params);
}

static void glGetTextureParameterfv(
    GLuint texture,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureParameterfv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureParameterfv(
            texture,
            pname,
            params);
}

static void glGetTextureParameteriv(
    GLuint texture,
    GLenum pname,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureParameteriv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glGetTextureParameteriv(
            texture,
            pname,
            params);
}

static void glGetTextureSubImage(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLenum type,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetTextureSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetTextureSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            bufSize,
            pixels);
}

static void glGetTransformFeedbackVarying(
    GLuint program,
    GLuint index,
    GLsizei bufSize,
    GLsizei *length,
    GLsizei *size,
    GLenum *type,
    GLchar *name) {
    if (IsWindows())
        gl3wProcs.ms.glGetTransformFeedbackVarying(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
    else
        gl3wProcs.sysv.glGetTransformFeedbackVarying(
            program,
            index,
            bufSize,
            length,
            size,
            type,
            name);
}

static void glGetTransformFeedbacki64_v(
    GLuint xfb,
    GLenum pname,
    GLuint index,
    GLint64 *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetTransformFeedbacki64_v(
            xfb,
            pname,
            index,
            param);
    else
        gl3wProcs.sysv.glGetTransformFeedbacki64_v(
            xfb,
            pname,
            index,
            param);
}

static void glGetTransformFeedbacki_v(
    GLuint xfb,
    GLenum pname,
    GLuint index,
    GLint *param) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetTransformFeedbacki_v(xfb, pname, index, param);
    else
        gl3wProcs.sysv
            .glGetTransformFeedbacki_v(xfb, pname, index, param);
}

static void glGetTransformFeedbackiv(
    GLuint xfb,
    GLenum pname,
    GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetTransformFeedbackiv(xfb, pname, param);
    else
        gl3wProcs.sysv.glGetTransformFeedbackiv(
            xfb,
            pname,
            param);
}

static void glGetUniformIndices(
    GLuint program,
    GLsizei uniformCount,
    const GLchar *const *uniformNames,
    GLuint *uniformIndices) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformIndices(
            program,
            uniformCount,
            uniformNames,
            uniformIndices);
    else
        gl3wProcs.sysv.glGetUniformIndices(
            program,
            uniformCount,
            uniformNames,
            uniformIndices);
}

static void glGetUniformSubroutineuiv(
    GLenum shadertype,
    GLint location,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformSubroutineuiv(
            shadertype,
            location,
            params);
    else
        gl3wProcs.sysv.glGetUniformSubroutineuiv(
            shadertype,
            location,
            params);
}

static void glGetUniformdv(
    GLuint program,
    GLint location,
    GLdouble *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformdv(program, location, params);
    else
        gl3wProcs.sysv.glGetUniformdv(program, location, params);
}

static void
glGetUniformfv(GLuint program, GLint location, GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformfv(program, location, params);
    else
        gl3wProcs.sysv.glGetUniformfv(program, location, params);
}

static void
glGetUniformiv(GLuint program, GLint location, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformiv(program, location, params);
    else
        gl3wProcs.sysv.glGetUniformiv(program, location, params);
}

static void
glGetUniformuiv(GLuint program, GLint location, GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetUniformuiv(program, location, params);
    else
        gl3wProcs.sysv.glGetUniformuiv(
            program,
            location,
            params);
}

static void glGetVertexArrayIndexed64iv(
    GLuint vaobj,
    GLuint index,
    GLenum pname,
    GLint64 *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexArrayIndexed64iv(
            vaobj,
            index,
            pname,
            param);
    else
        gl3wProcs.sysv.glGetVertexArrayIndexed64iv(
            vaobj,
            index,
            pname,
            param);
}

static void glGetVertexArrayIndexediv(
    GLuint vaobj,
    GLuint index,
    GLenum pname,
    GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexArrayIndexediv(
            vaobj,
            index,
            pname,
            param);
    else
        gl3wProcs.sysv.glGetVertexArrayIndexediv(
            vaobj,
            index,
            pname,
            param);
}

static void
glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexArrayiv(vaobj, pname, param);
    else
        gl3wProcs.sysv.glGetVertexArrayiv(vaobj, pname, param);
}

static void
glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribIiv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribIiv(
            index,
            pname,
            params);
}

static void glGetVertexAttribIuiv(
    GLuint index,
    GLenum pname,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribIuiv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribIuiv(
            index,
            pname,
            params);
}

static void glGetVertexAttribLdv(
    GLuint index,
    GLenum pname,
    GLdouble *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribLdv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribLdv(
            index,
            pname,
            params);
}

static void glGetVertexAttribPointerv(
    GLuint index,
    GLenum pname,
    void **pointer) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribPointerv(
            index,
            pname,
            pointer);
    else
        gl3wProcs.sysv.glGetVertexAttribPointerv(
            index,
            pname,
            pointer);
}

static void glGetVertexAttribdv(
    GLuint index,
    GLenum pname,
    GLdouble *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribdv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribdv(index, pname, params);
}

static void glGetVertexAttribfv(
    GLuint index,
    GLenum pname,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribfv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribfv(index, pname, params);
}

static void
glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetVertexAttribiv(index, pname, params);
    else
        gl3wProcs.sysv.glGetVertexAttribiv(index, pname, params);
}

static void glGetnCompressedTexImage(
    GLenum target,
    GLint lod,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetnCompressedTexImage(
            target,
            lod,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetnCompressedTexImage(
            target,
            lod,
            bufSize,
            pixels);
}

static void glGetnTexImage(
    GLenum target,
    GLint level,
    GLenum format,
    GLenum type,
    GLsizei bufSize,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glGetnTexImage(
            target,
            level,
            format,
            type,
            bufSize,
            pixels);
    else
        gl3wProcs.sysv.glGetnTexImage(
            target,
            level,
            format,
            type,
            bufSize,
            pixels);
}

static void glGetnUniformdv(
    GLuint program,
    GLint location,
    GLsizei bufSize,
    GLdouble *params) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetnUniformdv(program, location, bufSize, params);
    else
        gl3wProcs.sysv
            .glGetnUniformdv(program, location, bufSize, params);
}

static void glGetnUniformfv(
    GLuint program,
    GLint location,
    GLsizei bufSize,
    GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetnUniformfv(program, location, bufSize, params);
    else
        gl3wProcs.sysv
            .glGetnUniformfv(program, location, bufSize, params);
}

static void glGetnUniformiv(
    GLuint program,
    GLint location,
    GLsizei bufSize,
    GLint *params) {
    if (IsWindows())
        gl3wProcs.ms
            .glGetnUniformiv(program, location, bufSize, params);
    else
        gl3wProcs.sysv
            .glGetnUniformiv(program, location, bufSize, params);
}

static void glGetnUniformuiv(
    GLuint program,
    GLint location,
    GLsizei bufSize,
    GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glGetnUniformuiv(
            program,
            location,
            bufSize,
            params);
    else
        gl3wProcs.sysv.glGetnUniformuiv(
            program,
            location,
            bufSize,
            params);
}

static void glHint(GLenum target, GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glHint(target, mode);
    else
        gl3wProcs.sysv.glHint(target, mode);
}

static void glInvalidateBufferData(GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateBufferData(buffer);
    else
        gl3wProcs.sysv.glInvalidateBufferData(buffer);
}

static void glInvalidateBufferSubData(
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr length) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateBufferSubData(
            buffer,
            offset,
            length);
    else
        gl3wProcs.sysv.glInvalidateBufferSubData(
            buffer,
            offset,
            length);
}

static void glInvalidateFramebuffer(
    GLenum target,
    GLsizei numAttachments,
    const GLenum *attachments) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateFramebuffer(
            target,
            numAttachments,
            attachments);
    else
        gl3wProcs.sysv.glInvalidateFramebuffer(
            target,
            numAttachments,
            attachments);
}

static void glInvalidateNamedFramebufferData(
    GLuint framebuffer,
    GLsizei numAttachments,
    const GLenum *attachments) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateNamedFramebufferData(
            framebuffer,
            numAttachments,
            attachments);
    else
        gl3wProcs.sysv.glInvalidateNamedFramebufferData(
            framebuffer,
            numAttachments,
            attachments);
}

static void glInvalidateNamedFramebufferSubData(
    GLuint framebuffer,
    GLsizei numAttachments,
    const GLenum *attachments,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateNamedFramebufferSubData(
            framebuffer,
            numAttachments,
            attachments,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glInvalidateNamedFramebufferSubData(
            framebuffer,
            numAttachments,
            attachments,
            x,
            y,
            width,
            height);
}

static void glInvalidateSubFramebuffer(
    GLenum target,
    GLsizei numAttachments,
    const GLenum *attachments,
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateSubFramebuffer(
            target,
            numAttachments,
            attachments,
            x,
            y,
            width,
            height);
    else
        gl3wProcs.sysv.glInvalidateSubFramebuffer(
            target,
            numAttachments,
            attachments,
            x,
            y,
            width,
            height);
}

static void glInvalidateTexImage(GLuint texture, GLint level) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateTexImage(texture, level);
    else
        gl3wProcs.sysv.glInvalidateTexImage(texture, level);
}

static void glInvalidateTexSubImage(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth) {
    if (IsWindows())
        gl3wProcs.ms.glInvalidateTexSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth);
    else
        gl3wProcs.sysv.glInvalidateTexSubImage(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth);
}

static void glLineWidth(GLfloat width) {
    if (IsWindows())
        gl3wProcs.ms.glLineWidth(width);
    else
        gl3wProcs.sysv.glLineWidth(width);
}

static void glLinkProgram(GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glLinkProgram(program);
    else
        gl3wProcs.sysv.glLinkProgram(program);
}

static void glLogicOp(GLenum opcode) {
    if (IsWindows())
        gl3wProcs.ms.glLogicOp(opcode);
    else
        gl3wProcs.sysv.glLogicOp(opcode);
}

static void glMemoryBarrier(GLbitfield barriers) {
    if (IsWindows())
        gl3wProcs.ms.glMemoryBarrier(barriers);
    else
        gl3wProcs.sysv.glMemoryBarrier(barriers);
}

static void glMemoryBarrierByRegion(GLbitfield barriers) {
    if (IsWindows())
        gl3wProcs.ms.glMemoryBarrierByRegion(barriers);
    else
        gl3wProcs.sysv.glMemoryBarrierByRegion(barriers);
}

static void glMinSampleShading(GLfloat value) {
    if (IsWindows())
        gl3wProcs.ms.glMinSampleShading(value);
    else
        gl3wProcs.sysv.glMinSampleShading(value);
}

static void glMultiDrawArrays(
    GLenum mode,
    const GLint *first,
    const GLsizei *count,
    GLsizei drawcount) {
    if (IsWindows())
        gl3wProcs.ms
            .glMultiDrawArrays(mode, first, count, drawcount);
    else
        gl3wProcs.sysv
            .glMultiDrawArrays(mode, first, count, drawcount);
}

static void glMultiDrawArraysIndirect(
    GLenum mode,
    const void *indirect,
    GLsizei drawcount,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawArraysIndirect(
            mode,
            indirect,
            drawcount,
            stride);
    else
        gl3wProcs.sysv.glMultiDrawArraysIndirect(
            mode,
            indirect,
            drawcount,
            stride);
}

static void glMultiDrawArraysIndirectCount(
    GLenum mode,
    const void *indirect,
    GLintptr drawcount,
    GLsizei maxdrawcount,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawArraysIndirectCount(
            mode,
            indirect,
            drawcount,
            maxdrawcount,
            stride);
    else
        gl3wProcs.sysv.glMultiDrawArraysIndirectCount(
            mode,
            indirect,
            drawcount,
            maxdrawcount,
            stride);
}

static void glMultiDrawElements(
    GLenum mode,
    const GLsizei *count,
    GLenum type,
    const void *const *indices,
    GLsizei drawcount) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawElements(
            mode,
            count,
            type,
            indices,
            drawcount);
    else
        gl3wProcs.sysv.glMultiDrawElements(
            mode,
            count,
            type,
            indices,
            drawcount);
}

static void glMultiDrawElementsBaseVertex(
    GLenum mode,
    const GLsizei *count,
    GLenum type,
    const void *const *indices,
    GLsizei drawcount,
    const GLint *basevertex) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawElementsBaseVertex(
            mode,
            count,
            type,
            indices,
            drawcount,
            basevertex);
    else
        gl3wProcs.sysv.glMultiDrawElementsBaseVertex(
            mode,
            count,
            type,
            indices,
            drawcount,
            basevertex);
}

static void glMultiDrawElementsIndirect(
    GLenum mode,
    GLenum type,
    const void *indirect,
    GLsizei drawcount,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawElementsIndirect(
            mode,
            type,
            indirect,
            drawcount,
            stride);
    else
        gl3wProcs.sysv.glMultiDrawElementsIndirect(
            mode,
            type,
            indirect,
            drawcount,
            stride);
}

static void glMultiDrawElementsIndirectCount(
    GLenum mode,
    GLenum type,
    const void *indirect,
    GLintptr drawcount,
    GLsizei maxdrawcount,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glMultiDrawElementsIndirectCount(
            mode,
            type,
            indirect,
            drawcount,
            maxdrawcount,
            stride);
    else
        gl3wProcs.sysv.glMultiDrawElementsIndirectCount(
            mode,
            type,
            indirect,
            drawcount,
            maxdrawcount,
            stride);
}

static void glNamedBufferData(
    GLuint buffer,
    GLsizeiptr size,
    const void *data,
    GLenum usage) {
    if (IsWindows())
        gl3wProcs.ms
            .glNamedBufferData(buffer, size, data, usage);
    else
        gl3wProcs.sysv
            .glNamedBufferData(buffer, size, data, usage);
}

static void glNamedBufferStorage(
    GLuint buffer,
    GLsizeiptr size,
    const void *data,
    GLbitfield flags) {
    if (IsWindows())
        gl3wProcs.ms
            .glNamedBufferStorage(buffer, size, data, flags);
    else
        gl3wProcs.sysv
            .glNamedBufferStorage(buffer, size, data, flags);
}

static void glNamedBufferSubData(
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size,
    const void *data) {
    if (IsWindows())
        gl3wProcs.ms
            .glNamedBufferSubData(buffer, offset, size, data);
    else
        gl3wProcs.sysv
            .glNamedBufferSubData(buffer, offset, size, data);
}

static void glNamedFramebufferDrawBuffer(
    GLuint framebuffer,
    GLenum buf) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferDrawBuffer(
            framebuffer,
            buf);
    else
        gl3wProcs.sysv.glNamedFramebufferDrawBuffer(
            framebuffer,
            buf);
}

static void glNamedFramebufferDrawBuffers(
    GLuint framebuffer,
    GLsizei n,
    const GLenum *bufs) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferDrawBuffers(
            framebuffer,
            n,
            bufs);
    else
        gl3wProcs.sysv.glNamedFramebufferDrawBuffers(
            framebuffer,
            n,
            bufs);
}

static void glNamedFramebufferParameteri(
    GLuint framebuffer,
    GLenum pname,
    GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferParameteri(
            framebuffer,
            pname,
            param);
    else
        gl3wProcs.sysv.glNamedFramebufferParameteri(
            framebuffer,
            pname,
            param);
}

static void glNamedFramebufferReadBuffer(
    GLuint framebuffer,
    GLenum src) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferReadBuffer(
            framebuffer,
            src);
    else
        gl3wProcs.sysv.glNamedFramebufferReadBuffer(
            framebuffer,
            src);
}

static void glNamedFramebufferRenderbuffer(
    GLuint framebuffer,
    GLenum attachment,
    GLenum renderbuffertarget,
    GLuint renderbuffer) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferRenderbuffer(
            framebuffer,
            attachment,
            renderbuffertarget,
            renderbuffer);
    else
        gl3wProcs.sysv.glNamedFramebufferRenderbuffer(
            framebuffer,
            attachment,
            renderbuffertarget,
            renderbuffer);
}

static void glNamedFramebufferTexture(
    GLuint framebuffer,
    GLenum attachment,
    GLuint texture,
    GLint level) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferTexture(
            framebuffer,
            attachment,
            texture,
            level);
    else
        gl3wProcs.sysv.glNamedFramebufferTexture(
            framebuffer,
            attachment,
            texture,
            level);
}

static void glNamedFramebufferTextureLayer(
    GLuint framebuffer,
    GLenum attachment,
    GLuint texture,
    GLint level,
    GLint layer) {
    if (IsWindows())
        gl3wProcs.ms.glNamedFramebufferTextureLayer(
            framebuffer,
            attachment,
            texture,
            level,
            layer);
    else
        gl3wProcs.sysv.glNamedFramebufferTextureLayer(
            framebuffer,
            attachment,
            texture,
            level,
            layer);
}

static void glNamedRenderbufferStorage(
    GLuint renderbuffer,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glNamedRenderbufferStorage(
            renderbuffer,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glNamedRenderbufferStorage(
            renderbuffer,
            internalformat,
            width,
            height);
}

static void glNamedRenderbufferStorageMultisample(
    GLuint renderbuffer,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glNamedRenderbufferStorageMultisample(
            renderbuffer,
            samples,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glNamedRenderbufferStorageMultisample(
            renderbuffer,
            samples,
            internalformat,
            width,
            height);
}

static void glObjectLabel(
    GLenum identifier,
    GLuint name,
    GLsizei length,
    const GLchar *label) {
    if (IsWindows())
        gl3wProcs.ms
            .glObjectLabel(identifier, name, length, label);
    else
        gl3wProcs.sysv
            .glObjectLabel(identifier, name, length, label);
}

static void glObjectPtrLabel(
    const void *ptr,
    GLsizei length,
    const GLchar *label) {
    if (IsWindows())
        gl3wProcs.ms.glObjectPtrLabel(ptr, length, label);
    else
        gl3wProcs.sysv.glObjectPtrLabel(ptr, length, label);
}

static void glPatchParameterfv(
    GLenum pname,
    const GLfloat *values) {
    if (IsWindows())
        gl3wProcs.ms.glPatchParameterfv(pname, values);
    else
        gl3wProcs.sysv.glPatchParameterfv(pname, values);
}

static void glPatchParameteri(GLenum pname, GLint value) {
    if (IsWindows())
        gl3wProcs.ms.glPatchParameteri(pname, value);
    else
        gl3wProcs.sysv.glPatchParameteri(pname, value);
}

static void glPauseTransformFeedback(void) {
    if (IsWindows())
        gl3wProcs.ms.glPauseTransformFeedback();
    else
        gl3wProcs.sysv.glPauseTransformFeedback();
}

static void glPixelStoref(GLenum pname, GLfloat param) {
    if (IsWindows())
        gl3wProcs.ms.glPixelStoref(pname, param);
    else
        gl3wProcs.sysv.glPixelStoref(pname, param);
}

static void glPixelStorei(GLenum pname, GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glPixelStorei(pname, param);
    else
        gl3wProcs.sysv.glPixelStorei(pname, param);
}

static void glPointParameterf(GLenum pname, GLfloat param) {
    if (IsWindows())
        gl3wProcs.ms.glPointParameterf(pname, param);
    else
        gl3wProcs.sysv.glPointParameterf(pname, param);
}

static void glPointParameterfv(
    GLenum pname,
    const GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glPointParameterfv(pname, params);
    else
        gl3wProcs.sysv.glPointParameterfv(pname, params);
}

static void glPointParameteri(GLenum pname, GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glPointParameteri(pname, param);
    else
        gl3wProcs.sysv.glPointParameteri(pname, param);
}

static void glPointParameteriv(
    GLenum pname,
    const GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glPointParameteriv(pname, params);
    else
        gl3wProcs.sysv.glPointParameteriv(pname, params);
}

static void glPointSize(GLfloat size) {
    if (IsWindows())
        gl3wProcs.ms.glPointSize(size);
    else
        gl3wProcs.sysv.glPointSize(size);
}

static void glPolygonMode(GLenum face, GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glPolygonMode(face, mode);
    else
        gl3wProcs.sysv.glPolygonMode(face, mode);
}

static void glPolygonOffset(GLfloat factor, GLfloat units) {
    if (IsWindows())
        gl3wProcs.ms.glPolygonOffset(factor, units);
    else
        gl3wProcs.sysv.glPolygonOffset(factor, units);
}

static void glPolygonOffsetClamp(
    GLfloat factor,
    GLfloat units,
    GLfloat clamp) {
    if (IsWindows())
        gl3wProcs.ms.glPolygonOffsetClamp(factor, units, clamp);
    else
        gl3wProcs.sysv.glPolygonOffsetClamp(
            factor,
            units,
            clamp);
}

static void glPopDebugGroup(void) {
    if (IsWindows())
        gl3wProcs.ms.glPopDebugGroup();
    else
        gl3wProcs.sysv.glPopDebugGroup();
}

static void glPrimitiveRestartIndex(GLuint index) {
    if (IsWindows())
        gl3wProcs.ms.glPrimitiveRestartIndex(index);
    else
        gl3wProcs.sysv.glPrimitiveRestartIndex(index);
}

static void glProgramBinary(
    GLuint program,
    GLenum binaryFormat,
    const void *binary,
    GLsizei length) {
    if (IsWindows())
        gl3wProcs.ms.glProgramBinary(
            program,
            binaryFormat,
            binary,
            length);
    else
        gl3wProcs.sysv.glProgramBinary(
            program,
            binaryFormat,
            binary,
            length);
}

static void
glProgramParameteri(GLuint program, GLenum pname, GLint value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramParameteri(program, pname, value);
    else
        gl3wProcs.sysv.glProgramParameteri(
            program,
            pname,
            value);
}

static void
glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1d(program, location, v0);
    else
        gl3wProcs.sysv.glProgramUniform1d(program, location, v0);
}

static void glProgramUniform1dv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1dv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform1dv(
            program,
            location,
            count,
            value);
}

static void
glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1f(program, location, v0);
    else
        gl3wProcs.sysv.glProgramUniform1f(program, location, v0);
}

static void glProgramUniform1fv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1fv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform1fv(
            program,
            location,
            count,
            value);
}

static void
glProgramUniform1i(GLuint program, GLint location, GLint v0) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1i(program, location, v0);
    else
        gl3wProcs.sysv.glProgramUniform1i(program, location, v0);
}

static void glProgramUniform1iv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1iv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform1iv(
            program,
            location,
            count,
            value);
}

static void
glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1ui(program, location, v0);
    else
        gl3wProcs.sysv.glProgramUniform1ui(
            program,
            location,
            v0);
}

static void glProgramUniform1uiv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform1uiv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform1uiv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform2d(
    GLuint program,
    GLint location,
    GLdouble v0,
    GLdouble v1) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform2d(program, location, v0, v1);
    else
        gl3wProcs.sysv
            .glProgramUniform2d(program, location, v0, v1);
}

static void glProgramUniform2dv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform2dv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform2dv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform2f(
    GLuint program,
    GLint location,
    GLfloat v0,
    GLfloat v1) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform2f(program, location, v0, v1);
    else
        gl3wProcs.sysv
            .glProgramUniform2f(program, location, v0, v1);
}

static void glProgramUniform2fv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform2fv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform2fv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform2i(
    GLuint program,
    GLint location,
    GLint v0,
    GLint v1) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform2i(program, location, v0, v1);
    else
        gl3wProcs.sysv
            .glProgramUniform2i(program, location, v0, v1);
}

static void glProgramUniform2iv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform2iv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform2iv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform2ui(
    GLuint program,
    GLint location,
    GLuint v0,
    GLuint v1) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform2ui(program, location, v0, v1);
    else
        gl3wProcs.sysv
            .glProgramUniform2ui(program, location, v0, v1);
}

static void glProgramUniform2uiv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform2uiv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform2uiv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform3d(
    GLuint program,
    GLint location,
    GLdouble v0,
    GLdouble v1,
    GLdouble v2) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform3d(program, location, v0, v1, v2);
    else
        gl3wProcs.sysv
            .glProgramUniform3d(program, location, v0, v1, v2);
}

static void glProgramUniform3dv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform3dv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform3dv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform3f(
    GLuint program,
    GLint location,
    GLfloat v0,
    GLfloat v1,
    GLfloat v2) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform3f(program, location, v0, v1, v2);
    else
        gl3wProcs.sysv
            .glProgramUniform3f(program, location, v0, v1, v2);
}

static void glProgramUniform3fv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform3fv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform3fv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform3i(
    GLuint program,
    GLint location,
    GLint v0,
    GLint v1,
    GLint v2) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform3i(program, location, v0, v1, v2);
    else
        gl3wProcs.sysv
            .glProgramUniform3i(program, location, v0, v1, v2);
}

static void glProgramUniform3iv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform3iv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform3iv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform3ui(
    GLuint program,
    GLint location,
    GLuint v0,
    GLuint v1,
    GLuint v2) {
    if (IsWindows())
        gl3wProcs.ms
            .glProgramUniform3ui(program, location, v0, v1, v2);
    else
        gl3wProcs.sysv
            .glProgramUniform3ui(program, location, v0, v1, v2);
}

static void glProgramUniform3uiv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform3uiv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform3uiv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform4d(
    GLuint program,
    GLint location,
    GLdouble v0,
    GLdouble v1,
    GLdouble v2,
    GLdouble v3) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4d(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
    else
        gl3wProcs.sysv.glProgramUniform4d(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
}

static void glProgramUniform4dv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4dv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform4dv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform4f(
    GLuint program,
    GLint location,
    GLfloat v0,
    GLfloat v1,
    GLfloat v2,
    GLfloat v3) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4f(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
    else
        gl3wProcs.sysv.glProgramUniform4f(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
}

static void glProgramUniform4fv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4fv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform4fv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform4i(
    GLuint program,
    GLint location,
    GLint v0,
    GLint v1,
    GLint v2,
    GLint v3) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4i(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
    else
        gl3wProcs.sysv.glProgramUniform4i(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
}

static void glProgramUniform4iv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4iv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform4iv(
            program,
            location,
            count,
            value);
}

static void glProgramUniform4ui(
    GLuint program,
    GLint location,
    GLuint v0,
    GLuint v1,
    GLuint v2,
    GLuint v3) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4ui(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
    else
        gl3wProcs.sysv.glProgramUniform4ui(
            program,
            location,
            v0,
            v1,
            v2,
            v3);
}

static void glProgramUniform4uiv(
    GLuint program,
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniform4uiv(
            program,
            location,
            count,
            value);
    else
        gl3wProcs.sysv.glProgramUniform4uiv(
            program,
            location,
            count,
            value);
}

static void glProgramUniformMatrix2dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix2fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix2x3dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2x3dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2x3dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix2x3fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2x3fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2x3fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix2x4dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2x4dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2x4dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix2x4fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix2x4fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix2x4fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3x2dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3x2dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3x2dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3x2fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3x2fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3x2fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3x4dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3x4dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3x4dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix3x4fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix3x4fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix3x4fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4x2dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4x2dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4x2dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4x2fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4x2fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4x2fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4x3dv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4x3dv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4x3dv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProgramUniformMatrix4x3fv(
    GLuint program,
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glProgramUniformMatrix4x3fv(
            program,
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glProgramUniformMatrix4x3fv(
            program,
            location,
            count,
            transpose,
            value);
}

static void glProvokingVertex(GLenum mode) {
    if (IsWindows())
        gl3wProcs.ms.glProvokingVertex(mode);
    else
        gl3wProcs.sysv.glProvokingVertex(mode);
}

static void glPushDebugGroup(
    GLenum source,
    GLuint id,
    GLsizei length,
    const GLchar *message) {
    if (IsWindows())
        gl3wProcs.ms
            .glPushDebugGroup(source, id, length, message);
    else
        gl3wProcs.sysv
            .glPushDebugGroup(source, id, length, message);
}

static void glQueryCounter(GLuint id, GLenum target) {
    if (IsWindows())
        gl3wProcs.ms.glQueryCounter(id, target);
    else
        gl3wProcs.sysv.glQueryCounter(id, target);
}

static void glReadBuffer(GLenum src) {
    if (IsWindows())
        gl3wProcs.ms.glReadBuffer(src);
    else
        gl3wProcs.sysv.glReadBuffer(src);
}

static void glReadPixels(
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glReadPixels(
            x,
            y,
            width,
            height,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glReadPixels(
            x,
            y,
            width,
            height,
            format,
            type,
            pixels);
}

static void glReadnPixels(
    GLint x,
    GLint y,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    GLsizei bufSize,
    void *data) {
    if (IsWindows())
        gl3wProcs.ms.glReadnPixels(
            x,
            y,
            width,
            height,
            format,
            type,
            bufSize,
            data);
    else
        gl3wProcs.sysv.glReadnPixels(
            x,
            y,
            width,
            height,
            format,
            type,
            bufSize,
            data);
}

static void glReleaseShaderCompiler(void) {
    if (IsWindows())
        gl3wProcs.ms.glReleaseShaderCompiler();
    else
        gl3wProcs.sysv.glReleaseShaderCompiler();
}

static void glRenderbufferStorage(
    GLenum target,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glRenderbufferStorage(
            target,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glRenderbufferStorage(
            target,
            internalformat,
            width,
            height);
}

static void glRenderbufferStorageMultisample(
    GLenum target,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glRenderbufferStorageMultisample(
            target,
            samples,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glRenderbufferStorageMultisample(
            target,
            samples,
            internalformat,
            width,
            height);
}

static void glResumeTransformFeedback(void) {
    if (IsWindows())
        gl3wProcs.ms.glResumeTransformFeedback();
    else
        gl3wProcs.sysv.glResumeTransformFeedback();
}

static void glSampleCoverage(GLfloat value, GLboolean invert) {
    if (IsWindows())
        gl3wProcs.ms.glSampleCoverage(value, invert);
    else
        gl3wProcs.sysv.glSampleCoverage(value, invert);
}

static void glSampleMaski(GLuint maskNumber, GLbitfield mask) {
    if (IsWindows())
        gl3wProcs.ms.glSampleMaski(maskNumber, mask);
    else
        gl3wProcs.sysv.glSampleMaski(maskNumber, mask);
}

static void glSamplerParameterIiv(
    GLuint sampler,
    GLenum pname,
    const GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameterIiv(
            sampler,
            pname,
            param);
    else
        gl3wProcs.sysv.glSamplerParameterIiv(
            sampler,
            pname,
            param);
}

static void glSamplerParameterIuiv(
    GLuint sampler,
    GLenum pname,
    const GLuint *param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameterIuiv(
            sampler,
            pname,
            param);
    else
        gl3wProcs.sysv.glSamplerParameterIuiv(
            sampler,
            pname,
            param);
}

static void glSamplerParameterf(
    GLuint sampler,
    GLenum pname,
    GLfloat param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameterf(sampler, pname, param);
    else
        gl3wProcs.sysv.glSamplerParameterf(
            sampler,
            pname,
            param);
}

static void glSamplerParameterfv(
    GLuint sampler,
    GLenum pname,
    const GLfloat *param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameterfv(sampler, pname, param);
    else
        gl3wProcs.sysv.glSamplerParameterfv(
            sampler,
            pname,
            param);
}

static void
glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameteri(sampler, pname, param);
    else
        gl3wProcs.sysv.glSamplerParameteri(
            sampler,
            pname,
            param);
}

static void glSamplerParameteriv(
    GLuint sampler,
    GLenum pname,
    const GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glSamplerParameteriv(sampler, pname, param);
    else
        gl3wProcs.sysv.glSamplerParameteriv(
            sampler,
            pname,
            param);
}

static void
glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glScissor(x, y, width, height);
    else
        gl3wProcs.sysv.glScissor(x, y, width, height);
}

static void
glScissorArrayv(GLuint first, GLsizei count, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glScissorArrayv(first, count, v);
    else
        gl3wProcs.sysv.glScissorArrayv(first, count, v);
}

static void glScissorIndexed(
    GLuint index,
    GLint left,
    GLint bottom,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glScissorIndexed(
            index,
            left,
            bottom,
            width,
            height);
    else
        gl3wProcs.sysv.glScissorIndexed(
            index,
            left,
            bottom,
            width,
            height);
}

static void glScissorIndexedv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glScissorIndexedv(index, v);
    else
        gl3wProcs.sysv.glScissorIndexedv(index, v);
}

static void glShaderBinary(
    GLsizei count,
    const GLuint *shaders,
    GLenum binaryFormat,
    const void *binary,
    GLsizei length) {
    if (IsWindows())
        gl3wProcs.ms.glShaderBinary(
            count,
            shaders,
            binaryFormat,
            binary,
            length);
    else
        gl3wProcs.sysv.glShaderBinary(
            count,
            shaders,
            binaryFormat,
            binary,
            length);
}

static void glShaderSource(
    GLuint shader,
    GLsizei count,
    const GLchar *const *string,
    const GLint *length) {
    if (IsWindows())
        gl3wProcs.ms
            .glShaderSource(shader, count, string, length);
    else
        gl3wProcs.sysv
            .glShaderSource(shader, count, string, length);
}

static void glShaderStorageBlockBinding(
    GLuint program,
    GLuint storageBlockIndex,
    GLuint storageBlockBinding) {
    if (IsWindows())
        gl3wProcs.ms.glShaderStorageBlockBinding(
            program,
            storageBlockIndex,
            storageBlockBinding);
    else
        gl3wProcs.sysv.glShaderStorageBlockBinding(
            program,
            storageBlockIndex,
            storageBlockBinding);
}

static void glSpecializeShader(
    GLuint shader,
    const GLchar *pEntryPoint,
    GLuint numSpecializationConstants,
    const GLuint *pConstantIndex,
    const GLuint *pConstantValue) {
    if (IsWindows())
        gl3wProcs.ms.glSpecializeShader(
            shader,
            pEntryPoint,
            numSpecializationConstants,
            pConstantIndex,
            pConstantValue);
    else
        gl3wProcs.sysv.glSpecializeShader(
            shader,
            pEntryPoint,
            numSpecializationConstants,
            pConstantIndex,
            pConstantValue);
}

static void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    if (IsWindows())
        gl3wProcs.ms.glStencilFunc(func, ref, mask);
    else
        gl3wProcs.sysv.glStencilFunc(func, ref, mask);
}

static void glStencilFuncSeparate(
    GLenum face,
    GLenum func,
    GLint ref,
    GLuint mask) {
    if (IsWindows())
        gl3wProcs.ms
            .glStencilFuncSeparate(face, func, ref, mask);
    else
        gl3wProcs.sysv
            .glStencilFuncSeparate(face, func, ref, mask);
}

static void glStencilMask(GLuint mask) {
    if (IsWindows())
        gl3wProcs.ms.glStencilMask(mask);
    else
        gl3wProcs.sysv.glStencilMask(mask);
}

static void glStencilMaskSeparate(GLenum face, GLuint mask) {
    if (IsWindows())
        gl3wProcs.ms.glStencilMaskSeparate(face, mask);
    else
        gl3wProcs.sysv.glStencilMaskSeparate(face, mask);
}

static void
glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    if (IsWindows())
        gl3wProcs.ms.glStencilOp(fail, zfail, zpass);
    else
        gl3wProcs.sysv.glStencilOp(fail, zfail, zpass);
}

static void glStencilOpSeparate(
    GLenum face,
    GLenum sfail,
    GLenum dpfail,
    GLenum dppass) {
    if (IsWindows())
        gl3wProcs.ms
            .glStencilOpSeparate(face, sfail, dpfail, dppass);
    else
        gl3wProcs.sysv
            .glStencilOpSeparate(face, sfail, dpfail, dppass);
}

static void glTexBuffer(
    GLenum target,
    GLenum internalformat,
    GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glTexBuffer(target, internalformat, buffer);
    else
        gl3wProcs.sysv.glTexBuffer(
            target,
            internalformat,
            buffer);
}

static void glTexBufferRange(
    GLenum target,
    GLenum internalformat,
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glTexBufferRange(
            target,
            internalformat,
            buffer,
            offset,
            size);
    else
        gl3wProcs.sysv.glTexBufferRange(
            target,
            internalformat,
            buffer,
            offset,
            size);
}

static void glTexImage1D(
    GLenum target,
    GLint level,
    GLint internalformat,
    GLsizei width,
    GLint border,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexImage1D(
            target,
            level,
            internalformat,
            width,
            border,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexImage1D(
            target,
            level,
            internalformat,
            width,
            border,
            format,
            type,
            pixels);
}

static void glTexImage2D(
    GLenum target,
    GLint level,
    GLint internalformat,
    GLsizei width,
    GLsizei height,
    GLint border,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexImage2D(
            target,
            level,
            internalformat,
            width,
            height,
            border,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexImage2D(
            target,
            level,
            internalformat,
            width,
            height,
            border,
            format,
            type,
            pixels);
}

static void glTexImage2DMultisample(
    GLenum target,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTexImage2DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTexImage2DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
}

static void glTexImage3D(
    GLenum target,
    GLint level,
    GLint internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLint border,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexImage3D(
            target,
            level,
            internalformat,
            width,
            height,
            depth,
            border,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexImage3D(
            target,
            level,
            internalformat,
            width,
            height,
            depth,
            border,
            format,
            type,
            pixels);
}

static void glTexImage3DMultisample(
    GLenum target,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTexImage3DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTexImage3DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
}

static void glTexParameterIiv(
    GLenum target,
    GLenum pname,
    const GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameterIiv(target, pname, params);
    else
        gl3wProcs.sysv.glTexParameterIiv(target, pname, params);
}

static void glTexParameterIuiv(
    GLenum target,
    GLenum pname,
    const GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameterIuiv(target, pname, params);
    else
        gl3wProcs.sysv.glTexParameterIuiv(target, pname, params);
}

static void
glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameterf(target, pname, param);
    else
        gl3wProcs.sysv.glTexParameterf(target, pname, param);
}

static void glTexParameterfv(
    GLenum target,
    GLenum pname,
    const GLfloat *params) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameterfv(target, pname, params);
    else
        gl3wProcs.sysv.glTexParameterfv(target, pname, params);
}

static void
glTexParameteri(GLenum target, GLenum pname, GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameteri(target, pname, param);
    else
        gl3wProcs.sysv.glTexParameteri(target, pname, param);
}

static void glTexParameteriv(
    GLenum target,
    GLenum pname,
    const GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glTexParameteriv(target, pname, params);
    else
        gl3wProcs.sysv.glTexParameteriv(target, pname, params);
}

static void glTexStorage1D(
    GLenum target,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width) {
    if (IsWindows())
        gl3wProcs.ms.glTexStorage1D(
            target,
            levels,
            internalformat,
            width);
    else
        gl3wProcs.sysv.glTexStorage1D(
            target,
            levels,
            internalformat,
            width);
}

static void glTexStorage2D(
    GLenum target,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glTexStorage2D(
            target,
            levels,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glTexStorage2D(
            target,
            levels,
            internalformat,
            width,
            height);
}

static void glTexStorage2DMultisample(
    GLenum target,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTexStorage2DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTexStorage2DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
}

static void glTexStorage3D(
    GLenum target,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth) {
    if (IsWindows())
        gl3wProcs.ms.glTexStorage3D(
            target,
            levels,
            internalformat,
            width,
            height,
            depth);
    else
        gl3wProcs.sysv.glTexStorage3D(
            target,
            levels,
            internalformat,
            width,
            height,
            depth);
}

static void glTexStorage3DMultisample(
    GLenum target,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTexStorage3DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTexStorage3DMultisample(
            target,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
}

static void glTexSubImage1D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLsizei width,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexSubImage1D(
            target,
            level,
            xoffset,
            width,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexSubImage1D(
            target,
            level,
            xoffset,
            width,
            format,
            type,
            pixels);
}

static void glTexSubImage2D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexSubImage2D(
            target,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            type,
            pixels);
}

static void glTexSubImage3D(
    GLenum target,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTexSubImage3D(
            target,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            pixels);
}

static void glTextureBarrier(void) {
    if (IsWindows())
        gl3wProcs.ms.glTextureBarrier();
    else
        gl3wProcs.sysv.glTextureBarrier();
}

static void glTextureBuffer(
    GLuint texture,
    GLenum internalformat,
    GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glTextureBuffer(
            texture,
            internalformat,
            buffer);
    else
        gl3wProcs.sysv.glTextureBuffer(
            texture,
            internalformat,
            buffer);
}

static void glTextureBufferRange(
    GLuint texture,
    GLenum internalformat,
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glTextureBufferRange(
            texture,
            internalformat,
            buffer,
            offset,
            size);
    else
        gl3wProcs.sysv.glTextureBufferRange(
            texture,
            internalformat,
            buffer,
            offset,
            size);
}

static void glTextureParameterIiv(
    GLuint texture,
    GLenum pname,
    const GLint *params) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameterIiv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glTextureParameterIiv(
            texture,
            pname,
            params);
}

static void glTextureParameterIuiv(
    GLuint texture,
    GLenum pname,
    const GLuint *params) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameterIuiv(
            texture,
            pname,
            params);
    else
        gl3wProcs.sysv.glTextureParameterIuiv(
            texture,
            pname,
            params);
}

static void glTextureParameterf(
    GLuint texture,
    GLenum pname,
    GLfloat param) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameterf(texture, pname, param);
    else
        gl3wProcs.sysv.glTextureParameterf(
            texture,
            pname,
            param);
}

static void glTextureParameterfv(
    GLuint texture,
    GLenum pname,
    const GLfloat *param) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameterfv(texture, pname, param);
    else
        gl3wProcs.sysv.glTextureParameterfv(
            texture,
            pname,
            param);
}

static void
glTextureParameteri(GLuint texture, GLenum pname, GLint param) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameteri(texture, pname, param);
    else
        gl3wProcs.sysv.glTextureParameteri(
            texture,
            pname,
            param);
}

static void glTextureParameteriv(
    GLuint texture,
    GLenum pname,
    const GLint *param) {
    if (IsWindows())
        gl3wProcs.ms.glTextureParameteriv(texture, pname, param);
    else
        gl3wProcs.sysv.glTextureParameteriv(
            texture,
            pname,
            param);
}

static void glTextureStorage1D(
    GLuint texture,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width) {
    if (IsWindows())
        gl3wProcs.ms.glTextureStorage1D(
            texture,
            levels,
            internalformat,
            width);
    else
        gl3wProcs.sysv.glTextureStorage1D(
            texture,
            levels,
            internalformat,
            width);
}

static void glTextureStorage2D(
    GLuint texture,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width,
    GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glTextureStorage2D(
            texture,
            levels,
            internalformat,
            width,
            height);
    else
        gl3wProcs.sysv.glTextureStorage2D(
            texture,
            levels,
            internalformat,
            width,
            height);
}

static void glTextureStorage2DMultisample(
    GLuint texture,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTextureStorage2DMultisample(
            texture,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTextureStorage2DMultisample(
            texture,
            samples,
            internalformat,
            width,
            height,
            fixedsamplelocations);
}

static void glTextureStorage3D(
    GLuint texture,
    GLsizei levels,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth) {
    if (IsWindows())
        gl3wProcs.ms.glTextureStorage3D(
            texture,
            levels,
            internalformat,
            width,
            height,
            depth);
    else
        gl3wProcs.sysv.glTextureStorage3D(
            texture,
            levels,
            internalformat,
            width,
            height,
            depth);
}

static void glTextureStorage3DMultisample(
    GLuint texture,
    GLsizei samples,
    GLenum internalformat,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLboolean fixedsamplelocations) {
    if (IsWindows())
        gl3wProcs.ms.glTextureStorage3DMultisample(
            texture,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
    else
        gl3wProcs.sysv.glTextureStorage3DMultisample(
            texture,
            samples,
            internalformat,
            width,
            height,
            depth,
            fixedsamplelocations);
}

static void glTextureSubImage1D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLsizei width,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTextureSubImage1D(
            texture,
            level,
            xoffset,
            width,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTextureSubImage1D(
            texture,
            level,
            xoffset,
            width,
            format,
            type,
            pixels);
}

static void glTextureSubImage2D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLsizei width,
    GLsizei height,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTextureSubImage2D(
            texture,
            level,
            xoffset,
            yoffset,
            width,
            height,
            format,
            type,
            pixels);
}

static void glTextureSubImage3D(
    GLuint texture,
    GLint level,
    GLint xoffset,
    GLint yoffset,
    GLint zoffset,
    GLsizei width,
    GLsizei height,
    GLsizei depth,
    GLenum format,
    GLenum type,
    const void *pixels) {
    if (IsWindows())
        gl3wProcs.ms.glTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            pixels);
    else
        gl3wProcs.sysv.glTextureSubImage3D(
            texture,
            level,
            xoffset,
            yoffset,
            zoffset,
            width,
            height,
            depth,
            format,
            type,
            pixels);
}

static void glTextureView(
    GLuint texture,
    GLenum target,
    GLuint origtexture,
    GLenum internalformat,
    GLuint minlevel,
    GLuint numlevels,
    GLuint minlayer,
    GLuint numlayers) {
    if (IsWindows())
        gl3wProcs.ms.glTextureView(
            texture,
            target,
            origtexture,
            internalformat,
            minlevel,
            numlevels,
            minlayer,
            numlayers);
    else
        gl3wProcs.sysv.glTextureView(
            texture,
            target,
            origtexture,
            internalformat,
            minlevel,
            numlevels,
            minlayer,
            numlayers);
}

static void glTransformFeedbackBufferBase(
    GLuint xfb,
    GLuint index,
    GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glTransformFeedbackBufferBase(
            xfb,
            index,
            buffer);
    else
        gl3wProcs.sysv.glTransformFeedbackBufferBase(
            xfb,
            index,
            buffer);
}

static void glTransformFeedbackBufferRange(
    GLuint xfb,
    GLuint index,
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr size) {
    if (IsWindows())
        gl3wProcs.ms.glTransformFeedbackBufferRange(
            xfb,
            index,
            buffer,
            offset,
            size);
    else
        gl3wProcs.sysv.glTransformFeedbackBufferRange(
            xfb,
            index,
            buffer,
            offset,
            size);
}

static void glTransformFeedbackVaryings(
    GLuint program,
    GLsizei count,
    const GLchar *const *varyings,
    GLenum bufferMode) {
    if (IsWindows())
        gl3wProcs.ms.glTransformFeedbackVaryings(
            program,
            count,
            varyings,
            bufferMode);
    else
        gl3wProcs.sysv.glTransformFeedbackVaryings(
            program,
            count,
            varyings,
            bufferMode);
}

static void glUniform1d(GLint location, GLdouble x) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1d(location, x);
    else
        gl3wProcs.sysv.glUniform1d(location, x);
}

static void glUniform1dv(
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1dv(location, count, value);
    else
        gl3wProcs.sysv.glUniform1dv(location, count, value);
}

static void glUniform1f(GLint location, GLfloat v0) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1f(location, v0);
    else
        gl3wProcs.sysv.glUniform1f(location, v0);
}

static void glUniform1fv(
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1fv(location, count, value);
    else
        gl3wProcs.sysv.glUniform1fv(location, count, value);
}

static void glUniform1i(GLint location, GLint v0) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1i(location, v0);
    else
        gl3wProcs.sysv.glUniform1i(location, v0);
}

static void
glUniform1iv(GLint location, GLsizei count, const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1iv(location, count, value);
    else
        gl3wProcs.sysv.glUniform1iv(location, count, value);
}

static void glUniform1ui(GLint location, GLuint v0) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1ui(location, v0);
    else
        gl3wProcs.sysv.glUniform1ui(location, v0);
}

static void glUniform1uiv(
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform1uiv(location, count, value);
    else
        gl3wProcs.sysv.glUniform1uiv(location, count, value);
}

static void glUniform2d(GLint location, GLdouble x, GLdouble y) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2d(location, x, y);
    else
        gl3wProcs.sysv.glUniform2d(location, x, y);
}

static void glUniform2dv(
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2dv(location, count, value);
    else
        gl3wProcs.sysv.glUniform2dv(location, count, value);
}

static void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2f(location, v0, v1);
    else
        gl3wProcs.sysv.glUniform2f(location, v0, v1);
}

static void glUniform2fv(
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2fv(location, count, value);
    else
        gl3wProcs.sysv.glUniform2fv(location, count, value);
}

static void glUniform2i(GLint location, GLint v0, GLint v1) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2i(location, v0, v1);
    else
        gl3wProcs.sysv.glUniform2i(location, v0, v1);
}

static void
glUniform2iv(GLint location, GLsizei count, const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2iv(location, count, value);
    else
        gl3wProcs.sysv.glUniform2iv(location, count, value);
}

static void glUniform2ui(GLint location, GLuint v0, GLuint v1) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2ui(location, v0, v1);
    else
        gl3wProcs.sysv.glUniform2ui(location, v0, v1);
}

static void glUniform2uiv(
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform2uiv(location, count, value);
    else
        gl3wProcs.sysv.glUniform2uiv(location, count, value);
}

static void
glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3d(location, x, y, z);
    else
        gl3wProcs.sysv.glUniform3d(location, x, y, z);
}

static void glUniform3dv(
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3dv(location, count, value);
    else
        gl3wProcs.sysv.glUniform3dv(location, count, value);
}

static void
glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3f(location, v0, v1, v2);
    else
        gl3wProcs.sysv.glUniform3f(location, v0, v1, v2);
}

static void glUniform3fv(
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3fv(location, count, value);
    else
        gl3wProcs.sysv.glUniform3fv(location, count, value);
}

static void
glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3i(location, v0, v1, v2);
    else
        gl3wProcs.sysv.glUniform3i(location, v0, v1, v2);
}

static void
glUniform3iv(GLint location, GLsizei count, const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3iv(location, count, value);
    else
        gl3wProcs.sysv.glUniform3iv(location, count, value);
}

static void
glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3ui(location, v0, v1, v2);
    else
        gl3wProcs.sysv.glUniform3ui(location, v0, v1, v2);
}

static void glUniform3uiv(
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform3uiv(location, count, value);
    else
        gl3wProcs.sysv.glUniform3uiv(location, count, value);
}

static void glUniform4d(
    GLint location,
    GLdouble x,
    GLdouble y,
    GLdouble z,
    GLdouble w) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4d(location, x, y, z, w);
    else
        gl3wProcs.sysv.glUniform4d(location, x, y, z, w);
}

static void glUniform4dv(
    GLint location,
    GLsizei count,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4dv(location, count, value);
    else
        gl3wProcs.sysv.glUniform4dv(location, count, value);
}

static void glUniform4f(
    GLint location,
    GLfloat v0,
    GLfloat v1,
    GLfloat v2,
    GLfloat v3) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4f(location, v0, v1, v2, v3);
    else
        gl3wProcs.sysv.glUniform4f(location, v0, v1, v2, v3);
}

static void glUniform4fv(
    GLint location,
    GLsizei count,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4fv(location, count, value);
    else
        gl3wProcs.sysv.glUniform4fv(location, count, value);
}

static void glUniform4i(
    GLint location,
    GLint v0,
    GLint v1,
    GLint v2,
    GLint v3) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4i(location, v0, v1, v2, v3);
    else
        gl3wProcs.sysv.glUniform4i(location, v0, v1, v2, v3);
}

static void
glUniform4iv(GLint location, GLsizei count, const GLint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4iv(location, count, value);
    else
        gl3wProcs.sysv.glUniform4iv(location, count, value);
}

static void glUniform4ui(
    GLint location,
    GLuint v0,
    GLuint v1,
    GLuint v2,
    GLuint v3) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4ui(location, v0, v1, v2, v3);
    else
        gl3wProcs.sysv.glUniform4ui(location, v0, v1, v2, v3);
}

static void glUniform4uiv(
    GLint location,
    GLsizei count,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniform4uiv(location, count, value);
    else
        gl3wProcs.sysv.glUniform4uiv(location, count, value);
}

static void glUniformBlockBinding(
    GLuint program,
    GLuint uniformBlockIndex,
    GLuint uniformBlockBinding) {
    if (IsWindows())
        gl3wProcs.ms.glUniformBlockBinding(
            program,
            uniformBlockIndex,
            uniformBlockBinding);
    else
        gl3wProcs.sysv.glUniformBlockBinding(
            program,
            uniformBlockIndex,
            uniformBlockBinding);
}

static void glUniformMatrix2dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix2fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix2x3dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2x3dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2x3dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix2x3fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2x3fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2x3fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix2x4dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2x4dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2x4dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix2x4fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix2x4fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix2x4fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3x2dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3x2dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3x2dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3x2fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3x2fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3x2fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3x4dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3x4dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3x4dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix3x4fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix3x4fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix3x4fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4x2dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4x2dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4x2dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4x2fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4x2fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4x2fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4x3dv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLdouble *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4x3dv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4x3dv(
            location,
            count,
            transpose,
            value);
}

static void glUniformMatrix4x3fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat *value) {
    if (IsWindows())
        gl3wProcs.ms.glUniformMatrix4x3fv(
            location,
            count,
            transpose,
            value);
    else
        gl3wProcs.sysv.glUniformMatrix4x3fv(
            location,
            count,
            transpose,
            value);
}

static void glUniformSubroutinesuiv(
    GLenum shadertype,
    GLsizei count,
    const GLuint *indices) {
    if (IsWindows())
        gl3wProcs.ms.glUniformSubroutinesuiv(
            shadertype,
            count,
            indices);
    else
        gl3wProcs.sysv.glUniformSubroutinesuiv(
            shadertype,
            count,
            indices);
}

static void glUseProgram(GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glUseProgram(program);
    else
        gl3wProcs.sysv.glUseProgram(program);
}

static void glUseProgramStages(
    GLuint pipeline,
    GLbitfield stages,
    GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glUseProgramStages(
            pipeline,
            stages,
            program);
    else
        gl3wProcs.sysv.glUseProgramStages(
            pipeline,
            stages,
            program);
}

static void glValidateProgram(GLuint program) {
    if (IsWindows())
        gl3wProcs.ms.glValidateProgram(program);
    else
        gl3wProcs.sysv.glValidateProgram(program);
}

static void glValidateProgramPipeline(GLuint pipeline) {
    if (IsWindows())
        gl3wProcs.ms.glValidateProgramPipeline(pipeline);
    else
        gl3wProcs.sysv.glValidateProgramPipeline(pipeline);
}

static void glVertexArrayAttribBinding(
    GLuint vaobj,
    GLuint attribindex,
    GLuint bindingindex) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayAttribBinding(
            vaobj,
            attribindex,
            bindingindex);
    else
        gl3wProcs.sysv.glVertexArrayAttribBinding(
            vaobj,
            attribindex,
            bindingindex);
}

static void glVertexArrayAttribFormat(
    GLuint vaobj,
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayAttribFormat(
            vaobj,
            attribindex,
            size,
            type,
            normalized,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexArrayAttribFormat(
            vaobj,
            attribindex,
            size,
            type,
            normalized,
            relativeoffset);
}

static void glVertexArrayAttribIFormat(
    GLuint vaobj,
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayAttribIFormat(
            vaobj,
            attribindex,
            size,
            type,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexArrayAttribIFormat(
            vaobj,
            attribindex,
            size,
            type,
            relativeoffset);
}

static void glVertexArrayAttribLFormat(
    GLuint vaobj,
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayAttribLFormat(
            vaobj,
            attribindex,
            size,
            type,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexArrayAttribLFormat(
            vaobj,
            attribindex,
            size,
            type,
            relativeoffset);
}

static void glVertexArrayBindingDivisor(
    GLuint vaobj,
    GLuint bindingindex,
    GLuint divisor) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayBindingDivisor(
            vaobj,
            bindingindex,
            divisor);
    else
        gl3wProcs.sysv.glVertexArrayBindingDivisor(
            vaobj,
            bindingindex,
            divisor);
}

static void glVertexArrayElementBuffer(
    GLuint vaobj,
    GLuint buffer) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayElementBuffer(vaobj, buffer);
    else
        gl3wProcs.sysv.glVertexArrayElementBuffer(vaobj, buffer);
}

static void glVertexArrayVertexBuffer(
    GLuint vaobj,
    GLuint bindingindex,
    GLuint buffer,
    GLintptr offset,
    GLsizei stride) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayVertexBuffer(
            vaobj,
            bindingindex,
            buffer,
            offset,
            stride);
    else
        gl3wProcs.sysv.glVertexArrayVertexBuffer(
            vaobj,
            bindingindex,
            buffer,
            offset,
            stride);
}

static void glVertexArrayVertexBuffers(
    GLuint vaobj,
    GLuint first,
    GLsizei count,
    const GLuint *buffers,
    const GLintptr *offsets,
    const GLsizei *strides) {
    if (IsWindows())
        gl3wProcs.ms.glVertexArrayVertexBuffers(
            vaobj,
            first,
            count,
            buffers,
            offsets,
            strides);
    else
        gl3wProcs.sysv.glVertexArrayVertexBuffers(
            vaobj,
            first,
            count,
            buffers,
            offsets,
            strides);
}

static void glVertexAttrib1d(GLuint index, GLdouble x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1d(index, x);
    else
        gl3wProcs.sysv.glVertexAttrib1d(index, x);
}

static void glVertexAttrib1dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib1dv(index, v);
}

static void glVertexAttrib1f(GLuint index, GLfloat x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1f(index, x);
    else
        gl3wProcs.sysv.glVertexAttrib1f(index, x);
}

static void glVertexAttrib1fv(GLuint index, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1fv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib1fv(index, v);
}

static void glVertexAttrib1s(GLuint index, GLshort x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1s(index, x);
    else
        gl3wProcs.sysv.glVertexAttrib1s(index, x);
}

static void glVertexAttrib1sv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib1sv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib1sv(index, v);
}

static void
glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2d(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttrib2d(index, x, y);
}

static void glVertexAttrib2dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib2dv(index, v);
}

static void
glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2f(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttrib2f(index, x, y);
}

static void glVertexAttrib2fv(GLuint index, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2fv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib2fv(index, v);
}

static void
glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2s(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttrib2s(index, x, y);
}

static void glVertexAttrib2sv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib2sv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib2sv(index, v);
}

static void glVertexAttrib3d(
    GLuint index,
    GLdouble x,
    GLdouble y,
    GLdouble z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3d(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttrib3d(index, x, y, z);
}

static void glVertexAttrib3dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib3dv(index, v);
}

static void
glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3f(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttrib3f(index, x, y, z);
}

static void glVertexAttrib3fv(GLuint index, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3fv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib3fv(index, v);
}

static void
glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3s(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttrib3s(index, x, y, z);
}

static void glVertexAttrib3sv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib3sv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib3sv(index, v);
}

static void glVertexAttrib4Nbv(GLuint index, const GLbyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nbv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Nbv(index, v);
}

static void glVertexAttrib4Niv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Niv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Niv(index, v);
}

static void glVertexAttrib4Nsv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nsv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Nsv(index, v);
}

static void glVertexAttrib4Nub(
    GLuint index,
    GLubyte x,
    GLubyte y,
    GLubyte z,
    GLubyte w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nub(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttrib4Nub(index, x, y, z, w);
}

static void glVertexAttrib4Nubv(GLuint index, const GLubyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nubv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Nubv(index, v);
}

static void glVertexAttrib4Nuiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nuiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Nuiv(index, v);
}

static void glVertexAttrib4Nusv(
    GLuint index,
    const GLushort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4Nusv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4Nusv(index, v);
}

static void glVertexAttrib4bv(GLuint index, const GLbyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4bv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4bv(index, v);
}

static void glVertexAttrib4d(
    GLuint index,
    GLdouble x,
    GLdouble y,
    GLdouble z,
    GLdouble w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4d(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttrib4d(index, x, y, z, w);
}

static void glVertexAttrib4dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4dv(index, v);
}

static void glVertexAttrib4f(
    GLuint index,
    GLfloat x,
    GLfloat y,
    GLfloat z,
    GLfloat w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4f(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttrib4f(index, x, y, z, w);
}

static void glVertexAttrib4fv(GLuint index, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4fv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4fv(index, v);
}

static void glVertexAttrib4iv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4iv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4iv(index, v);
}

static void glVertexAttrib4s(
    GLuint index,
    GLshort x,
    GLshort y,
    GLshort z,
    GLshort w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4s(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttrib4s(index, x, y, z, w);
}

static void glVertexAttrib4sv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4sv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4sv(index, v);
}

static void glVertexAttrib4ubv(GLuint index, const GLubyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4ubv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4ubv(index, v);
}

static void glVertexAttrib4uiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4uiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4uiv(index, v);
}

static void glVertexAttrib4usv(GLuint index, const GLushort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttrib4usv(index, v);
    else
        gl3wProcs.sysv.glVertexAttrib4usv(index, v);
}

static void glVertexAttribBinding(
    GLuint attribindex,
    GLuint bindingindex) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribBinding(
            attribindex,
            bindingindex);
    else
        gl3wProcs.sysv.glVertexAttribBinding(
            attribindex,
            bindingindex);
}

static void glVertexAttribDivisor(GLuint index, GLuint divisor) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribDivisor(index, divisor);
    else
        gl3wProcs.sysv.glVertexAttribDivisor(index, divisor);
}

static void glVertexAttribFormat(
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribFormat(
            attribindex,
            size,
            type,
            normalized,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexAttribFormat(
            attribindex,
            size,
            type,
            normalized,
            relativeoffset);
}

static void glVertexAttribI1i(GLuint index, GLint x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI1i(index, x);
    else
        gl3wProcs.sysv.glVertexAttribI1i(index, x);
}

static void glVertexAttribI1iv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI1iv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI1iv(index, v);
}

static void glVertexAttribI1ui(GLuint index, GLuint x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI1ui(index, x);
    else
        gl3wProcs.sysv.glVertexAttribI1ui(index, x);
}

static void glVertexAttribI1uiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI1uiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI1uiv(index, v);
}

static void glVertexAttribI2i(GLuint index, GLint x, GLint y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI2i(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttribI2i(index, x, y);
}

static void glVertexAttribI2iv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI2iv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI2iv(index, v);
}

static void
glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI2ui(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttribI2ui(index, x, y);
}

static void glVertexAttribI2uiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI2uiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI2uiv(index, v);
}

static void
glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI3i(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttribI3i(index, x, y, z);
}

static void glVertexAttribI3iv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI3iv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI3iv(index, v);
}

static void
glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI3ui(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttribI3ui(index, x, y, z);
}

static void glVertexAttribI3uiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI3uiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI3uiv(index, v);
}

static void glVertexAttribI4bv(GLuint index, const GLbyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4bv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4bv(index, v);
}

static void glVertexAttribI4i(
    GLuint index,
    GLint x,
    GLint y,
    GLint z,
    GLint w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4i(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttribI4i(index, x, y, z, w);
}

static void glVertexAttribI4iv(GLuint index, const GLint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4iv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4iv(index, v);
}

static void glVertexAttribI4sv(GLuint index, const GLshort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4sv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4sv(index, v);
}

static void glVertexAttribI4ubv(GLuint index, const GLubyte *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4ubv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4ubv(index, v);
}

static void glVertexAttribI4ui(
    GLuint index,
    GLuint x,
    GLuint y,
    GLuint z,
    GLuint w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4ui(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttribI4ui(index, x, y, z, w);
}

static void glVertexAttribI4uiv(GLuint index, const GLuint *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4uiv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4uiv(index, v);
}

static void glVertexAttribI4usv(
    GLuint index,
    const GLushort *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribI4usv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribI4usv(index, v);
}

static void glVertexAttribIFormat(
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribIFormat(
            attribindex,
            size,
            type,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexAttribIFormat(
            attribindex,
            size,
            type,
            relativeoffset);
}

static void glVertexAttribIPointer(
    GLuint index,
    GLint size,
    GLenum type,
    GLsizei stride,
    const void *pointer) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribIPointer(
            index,
            size,
            type,
            stride,
            pointer);
    else
        gl3wProcs.sysv.glVertexAttribIPointer(
            index,
            size,
            type,
            stride,
            pointer);
}

static void glVertexAttribL1d(GLuint index, GLdouble x) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL1d(index, x);
    else
        gl3wProcs.sysv.glVertexAttribL1d(index, x);
}

static void glVertexAttribL1dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL1dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribL1dv(index, v);
}

static void
glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL2d(index, x, y);
    else
        gl3wProcs.sysv.glVertexAttribL2d(index, x, y);
}

static void glVertexAttribL2dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL2dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribL2dv(index, v);
}

static void glVertexAttribL3d(
    GLuint index,
    GLdouble x,
    GLdouble y,
    GLdouble z) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL3d(index, x, y, z);
    else
        gl3wProcs.sysv.glVertexAttribL3d(index, x, y, z);
}

static void glVertexAttribL3dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL3dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribL3dv(index, v);
}

static void glVertexAttribL4d(
    GLuint index,
    GLdouble x,
    GLdouble y,
    GLdouble z,
    GLdouble w) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL4d(index, x, y, z, w);
    else
        gl3wProcs.sysv.glVertexAttribL4d(index, x, y, z, w);
}

static void glVertexAttribL4dv(GLuint index, const GLdouble *v) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribL4dv(index, v);
    else
        gl3wProcs.sysv.glVertexAttribL4dv(index, v);
}

static void glVertexAttribLFormat(
    GLuint attribindex,
    GLint size,
    GLenum type,
    GLuint relativeoffset) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribLFormat(
            attribindex,
            size,
            type,
            relativeoffset);
    else
        gl3wProcs.sysv.glVertexAttribLFormat(
            attribindex,
            size,
            type,
            relativeoffset);
}

static void glVertexAttribLPointer(
    GLuint index,
    GLint size,
    GLenum type,
    GLsizei stride,
    const void *pointer) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribLPointer(
            index,
            size,
            type,
            stride,
            pointer);
    else
        gl3wProcs.sysv.glVertexAttribLPointer(
            index,
            size,
            type,
            stride,
            pointer);
}

static void glVertexAttribP1ui(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    GLuint value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP1ui(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP1ui(index, type, normalized, value);
}

static void glVertexAttribP1uiv(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP1uiv(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP1uiv(index, type, normalized, value);
}

static void glVertexAttribP2ui(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    GLuint value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP2ui(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP2ui(index, type, normalized, value);
}

static void glVertexAttribP2uiv(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP2uiv(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP2uiv(index, type, normalized, value);
}

static void glVertexAttribP3ui(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    GLuint value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP3ui(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP3ui(index, type, normalized, value);
}

static void glVertexAttribP3uiv(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP3uiv(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP3uiv(index, type, normalized, value);
}

static void glVertexAttribP4ui(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    GLuint value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP4ui(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP4ui(index, type, normalized, value);
}

static void glVertexAttribP4uiv(
    GLuint index,
    GLenum type,
    GLboolean normalized,
    const GLuint *value) {
    if (IsWindows())
        gl3wProcs.ms
            .glVertexAttribP4uiv(index, type, normalized, value);
    else
        gl3wProcs.sysv
            .glVertexAttribP4uiv(index, type, normalized, value);
}

static void glVertexAttribPointer(
    GLuint index,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    const void *pointer) {
    if (IsWindows())
        gl3wProcs.ms.glVertexAttribPointer(
            index,
            size,
            type,
            normalized,
            stride,
            pointer);
    else
        gl3wProcs.sysv.glVertexAttribPointer(
            index,
            size,
            type,
            normalized,
            stride,
            pointer);
}

static void glVertexBindingDivisor(
    GLuint bindingindex,
    GLuint divisor) {
    if (IsWindows())
        gl3wProcs.ms.glVertexBindingDivisor(
            bindingindex,
            divisor);
    else
        gl3wProcs.sysv.glVertexBindingDivisor(
            bindingindex,
            divisor);
}

static void
glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    if (IsWindows())
        gl3wProcs.ms.glViewport(x, y, width, height);
    else
        gl3wProcs.sysv.glViewport(x, y, width, height);
}

static void
glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glViewportArrayv(first, count, v);
    else
        gl3wProcs.sysv.glViewportArrayv(first, count, v);
}

static void glViewportIndexedf(
    GLuint index,
    GLfloat x,
    GLfloat y,
    GLfloat w,
    GLfloat h) {
    if (IsWindows())
        gl3wProcs.ms.glViewportIndexedf(index, x, y, w, h);
    else
        gl3wProcs.sysv.glViewportIndexedf(index, x, y, w, h);
}

static void glViewportIndexedfv(GLuint index, const GLfloat *v) {
    if (IsWindows())
        gl3wProcs.ms.glViewportIndexedfv(index, v);
    else
        gl3wProcs.sysv.glViewportIndexedfv(index, v);
}

static void
glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    if (IsWindows())
        gl3wProcs.ms.glWaitSync(sync, flags, timeout);
    else
        gl3wProcs.sysv.glWaitSync(sync, flags, timeout);
}

static void *glMapBuffer(GLenum target, GLenum access) {
    if (IsWindows())
        return gl3wProcs.ms.glMapBuffer(target, access);
    else
        return gl3wProcs.sysv.glMapBuffer(target, access);
}

static void *glMapBufferRange(
    GLenum target,
    GLintptr offset,
    GLsizeiptr length,
    GLbitfield access) {
    if (IsWindows())
        return gl3wProcs.ms
            .glMapBufferRange(target, offset, length, access);
    else
        return gl3wProcs.sysv
            .glMapBufferRange(target, offset, length, access);
}

static void *glMapNamedBuffer(GLuint buffer, GLenum access) {
    if (IsWindows())
        return gl3wProcs.ms.glMapNamedBuffer(buffer, access);
    else
        return gl3wProcs.sysv.glMapNamedBuffer(buffer, access);
}

static void *glMapNamedBufferRange(
    GLuint buffer,
    GLintptr offset,
    GLsizeiptr length,
    GLbitfield access) {
    if (IsWindows())
        return gl3wProcs.ms.glMapNamedBufferRange(
            buffer,
            offset,
            length,
            access);
    else
        return gl3wProcs.sysv.glMapNamedBufferRange(
            buffer,
            offset,
            length,
            access);
}

#ifdef __cplusplus
}
#endif

#endif
