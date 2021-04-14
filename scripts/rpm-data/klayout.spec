#
# spec file for package klayout
#
# Copyright (c) 2017 SUSE LINUX Products GmbH, Nuernberg, Germany.
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/
#

Name:           klayout
Version:        0.26.11
Release:        0
Summary:        KLayout, viewer and editor for mask layouts
License:        GPL-2.0+
Group:          Productivity/Scientific/Electronics
Url:            http://www.klayout.de
Source0:        https://www.klayout.org/downloads/source/%{name}-%{version}.tar.gz

# Disable auto-detection of dependencies (to prevent including the
# so's of klayout itself)
AutoReqProv: 	no

Requires: ruby >= 2.5.5
Requires: python3 >= 3.6.0
Requires: qt5-qtbase >= 5.11.1
Requires: qt5-qtmultimedia >= 5.11.1
Requires: qt5-qtxmlpatterns >= 5.11.1
Requires: qt5-qtsvg >= 5.11.1
Requires: qt5-qttools >= 5.11.1
# NOTE: this package is required for libQt5Designer and pulls in a lot of devel stuff.
# Maybe it's worth considering to drop designer support and replace by QUiLoader.
Requires: qt5-qttools-devel >= 5.11.1

## Provides qmake (qmake-qt5)
BuildRequires: qt5-qtbase-devel

%define buildopt -j2
%define pylib %{python_sitearch}
%define __python /usr/bin/python3

%description
Mask layout viewer and editor for the chip design engineer.

For details see README.md

%prep

%setup -q	

%build

TARGET="linux-release"

# do the actual build
./build.sh -rpath %{_libdir}/klayout \
           -bin %{_builddir}/bin.$TARGET \
           -build %{_builddir}/build.$TARGET \
           %{buildopt} 

cp -p LICENSE Changelog CONTRIB %{_builddir}
strip %{_builddir}/bin.$TARGET/*.so
strip %{_builddir}/bin.$TARGET/*/*.so
strip %{_builddir}/bin.$TARGET/*/*/*.so
strip %{_builddir}/bin.$TARGET/klayout
strip %{_builddir}/bin.$TARGET/strm*

%install

TARGET="linux-release"

# create and populate pylib
mkdir -p %{buildroot}%{pylib}/klayout
cp -pd %{_builddir}/bin.$TARGET/pymod/klayout/*.so %{buildroot}%{pylib}/klayout
cp -pd %{_builddir}/bin.$TARGET/pymod/klayout/*.py %{buildroot}%{pylib}/klayout
chmod 644 %{buildroot}%{pylib}/klayout/*
for d in tl db rdb; do
  mkdir -p %{buildroot}%{pylib}/klayout/$d
  cp -pd %{_builddir}/bin.$TARGET/pymod/klayout/$d/*.py %{buildroot}%{pylib}/klayout/$d
  chmod 644 %{buildroot}%{pylib}/klayout/$d/*
done

# create and populate libdir
mkdir -p %{buildroot}%{_libdir}/klayout
mkdir -p %{buildroot}%{_libdir}/klayout/db_plugins
mkdir -p %{buildroot}%{_libdir}/klayout/lay_plugins
cp -pd %{_builddir}/bin.$TARGET/lib*.so* %{buildroot}%{_libdir}/klayout
cp -pd %{_builddir}/bin.$TARGET/db_plugins/lib*.so* %{buildroot}%{_libdir}/klayout/db_plugins
cp -pd %{_builddir}/bin.$TARGET/lay_plugins/lib*.so* %{buildroot}%{_libdir}/klayout/lay_plugins
chmod 644 %{buildroot}%{_libdir}/klayout/*.so*
chmod 644 %{buildroot}%{_libdir}/klayout/db_plugins/*.so*
chmod 644 %{buildroot}%{_libdir}/klayout/lay_plugins/*.so*

# create and populate bindir
mkdir -p %{buildroot}%{_bindir}
cp -pd %{_builddir}/bin.$TARGET/klayout %{_builddir}/bin.$TARGET/strm* %{buildroot}%{_bindir}
chmod 755 %{buildroot}%{_bindir}/*

# other files
install -Dm644 %{_sourcedir}/etc/%{name}.desktop %{buildroot}%{_datadir}/applications/%{name}.desktop
install -Dm644 %{_sourcedir}/etc/logo.png %{buildroot}%{_datadir}/pixmaps/%{name}.png

# TODO: remove this? This macro does not expand to anything in SuSE 42.x
#%if 0%{?suse_version}%{?sles_version}
#%suse_update_desktop_file -n %{name}
#%endif

%files
%defattr(-,root,root)
%doc LICENSE
%doc Changelog
%doc CONTRIB
%{_bindir}/klayout
%{_bindir}/strm*
%{pylib}/klayout/*
%{_libdir}/klayout/*
%{_datadir}/applications/%{name}.desktop
%{_datadir}/pixmaps/%{name}.png

%changelog
