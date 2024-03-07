// ---------- Part 1 ----------
// export function middleware(request) {
//   console.log("requested: ", request.url);
// }

// export const config = {
//   matcher: ["/", "/about"],
// };


// ---------- Part 2 ----------
// export function middleware(request) {
//   if (request.nextUrl.pathname.startsWith("/about")) {
//     console.log("Visiting About");
//   }

//   if (request.nextUrl.pathname.startsWith("/api/users")) {
//     console.log("Visiting the Users API");
//   }
// }

// ---------- Part 3 ----------
// import { NextResponse } from 'next/server';

// export function middleware(request) {
//   const response = NextResponse.next();

//   if (request.nextUrl.pathname.startsWith('/setCookie')) {
//     let cookieMessage = request.nextUrl.searchParams.get('message');
//     response.cookies.set('message', cookieMessage);
//   }

//   if (request.nextUrl.pathname.startsWith('/getCookie')) {
//     let cookie = request.cookies.get('message');
//     console.log(cookie);
//   }

//   return response;
// }


// ---------- Part 4 ----------
// URL Rewrites​
import { NextResponse } from 'next/server';

export function middleware(request) {
  const requestHeaders = new Headers(request.headers);
  const language = requestHeaders.get('Accept-Language');

  if (language.includes('fr')) {
    return NextResponse.rewrite(new URL('/fr/about', request.url));
  }
}

export const config = {
  matcher: ['/about'],
};