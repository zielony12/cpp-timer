# Maintainer: Karol Purgal <xdzielony at gmail dot com>
# Contributor: Karol Purgal <xdzielony at gmail dot com>

pkgname=libtimer
pkgver=0.1.1
pkgrel=1
pkgdesc="A simple timer C++ library"
arch=('any')
url="https://github.com/zielony12/cpp-timer"
license=('GPL3')
makedepends=('make' 'gcc')
provides=('libtimer')
source=("${pkgname}"::git+https://github.com/zielony12/cpp-timer.git)
sha256sums=('SKIP')

build() {
	cd ${srcdir}/${pkgname}
	make
}

package() {
	install -Dm755 ${srcdir}/${pkgname}/bin/${pkgname}.so ${pkgdir}/usr/lib/${pkgname}.so
	install -Dm644 ${srcdir}/${pkgname}/include/timer/Countdown.hpp ${pkgdir}/usr/include/timer/Countdown.hpp
	install -Dm644 ${srcdir}/${pkgname}/include/timer/Stopwatch.hpp ${pkgdir}/usr/include/timer/Stopwatch.hpp
	install -Dm644 ${srcdir}/${pkgname}/include/timer/Timer.hpp 	${pkgdir}/usr/include/timer/Timer.hpp
	install -Dm644 ${srcdir}/${pkgname}/LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE
}
