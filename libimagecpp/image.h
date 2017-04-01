/*
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <memory>
#include <string>

namespace imlib_image {
struct __Image;
/**
 * @brief Image class to read and manipulate images.
 */
class Image {
public:
    Image ( const std::string & filename ) :
        filename_ ( filename ), width_ ( 0 ), height_ ( 0 ), loaded_ ( false ) {}

        Image ( const Image& ) = delete;
        Image ( Image&& ) = delete;
        Image& operator= ( const Image& ) = delete;
        Image& operator= ( Image&& ) = delete;
        ~Image();

    /**
         * @brief the image width
         * @return width
         */
        int width();
        /**
         * @brief the image height
         * @return height
         */
        int height();
        /**
         * @brief the image mime-type
         * @return mime-type
         */
        std::string mimeType();
    /**
     * @brief the image color depth
     * @return color depth
     */
    std::string colorDepth();
    /**
         * @brief write new scaled image
         * @param width new image width
         * @param height new image height
         * @param outfile the target filename
         */
        void scale ( const int & width, const int & height, const std::string & outfile );

private:
        const std::string filename_;
        int width_, height_;
        bool loaded_;

        std::string mime_type_;
        std::shared_ptr< __Image > image_;
        void init_();
};
}//namespace image
#endif // IMAGE_H
